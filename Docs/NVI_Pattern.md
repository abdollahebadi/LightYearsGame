# NVI Pattern in Application and World

## What is NVI?

NVI (Non-Virtual Interface) is a C++ design pattern where:
- The **public interface** is non-virtual — stable, owned by the base class
- The **virtual hooks** are private — customization points for subclasses only

Core idea: **the base class controls the "when" and "how", the subclass controls the "what".**

This enforces the **Hollywood Principle**: *"Don't call us, we'll call you."* Game code never drives
the loop — the framework calls game code at the right time.

---

## How Application and World mirror each other

Both classes follow the same NVI structure:

| | `Application` | `World` |
|---|---|---|
| **Public entry point** | `Run()` | `BeginWorldInternal()` / `ProgressWorldInternal()` |
| **Internal engine step** | `TickInternal()` / `RenderInternal()` | (driven by `Application::TickInternal`) |
| **Game hook** | `Tick()` / `Render()` | `BeginWorld()` / `ProgressWorld()` |
| **Who calls the hook** | Engine loop | `Application::TickInternal()` |
| **Who overrides the hook** | `GameApplication` | `GameWorld` (game-side subclass) |

They nest inside each other:

```
Application  →  owns and drives  →  World
     ↓                                  ↓
game overrides                   game overrides
Tick / Render                    BeginWorld / ProgressWorld
```

---

## Call sequence

```
main()
  └─ GetApplication()               ← game side provides this
       └─ new GameApplication()
            └─ SpawnWorld<T>()      ← game decides which World subclass
  └─ Run()
       └─ TickInternal(dt)
            └─ Tick(dt)             ← game hook (NVI)
            └─ BeginWorldInternal() ← fires once
                 └─ BeginWorld()    ← game hook (NVI)
            └─ ProgressWorldInternal(dt)
                 └─ ProgressWorld() ← game hook (NVI)
       └─ RenderInternal()
            └─ Render()             ← game hook (NVI)
```

---

## Responsibility boundary

The engine provides:
- Base classes (`Application`, `World`) with defined lifecycle hooks
- `SpawnWorld<T>()` — the mechanism to create and register a world
- The loop that drives everything each frame

The game provides:
- Subclasses of `Application` and `World` with game-specific logic
- The decision of which `World` subclass to spawn and when

The engine owns the **skeleton**, the game fills in the **content**.

---

## The NVI enforcement compromise in World

Full NVI would require `BeginWorldInternal`/`ProgressWorldInternal` to be `private`, since they
are engine internals and should not be callable by external code or game subclasses. However,
`Application::TickInternal()` needs to call them on `currentWorld`, which creates an access problem.

The options and their trade-offs:

| Approach | Trade-off |
|---|---|
| Keep them `public` | Simple, but any external code can call them — weakens encapsulation |
| `protected` + `friend Application` | World subclasses can also call them — too permissive |
| `private` + `friend Application` | Full NVI enforcement, but introduces tight coupling |

The course takes the `public` approach as a pragmatic compromise — the complexity of `friend` is not
worth it in a learning context and the engine is not a public-facing SDK used by strangers.

The architecturally correct approach for full NVI would be `private` + `friend class Application`:

```cpp
class World {
    friend class Application;  // only Application can drive the world lifecycle

public:
    World(Application* owningApp);
    virtual ~World() = default;

private:
    void BeginWorldInternal();
    void ProgressWorldInternal(float deltaTime);

    virtual void BeginWorld() {}
    virtual void ProgressWorld(float deltaTime) {}

    Application* owningApp;
    bool worldStarted;
};
```

`friend` is justified here because `Application` and `World` have an inherently tight, well-defined
relationship — `Application` owns `World` and is specifically responsible for driving it. Using
`friend` makes that explicit rather than hiding it behind `public`.

---

## NVI in other languages

NVI as a strict pattern is **C++ specific** because C++ uniquely separates access control from
override ability. Most other languages tie them together.

| Language | `private` overridable? | NVI equivalent |
|---|---|---|
| **C++** | Yes — override works, direct call from subclass does not | Full NVI with private virtual |
| **Kotlin** | No — `private open` is a compile error | Generic upper bound `<T : World>` |
| **Java** | No — private methods are hidden, not overridden | Same as Kotlin |
| **C#** | No — `private virtual` is rejected by compiler | Same as Kotlin |
| **Rust** | No inheritance — traits used instead | Trait bounds |