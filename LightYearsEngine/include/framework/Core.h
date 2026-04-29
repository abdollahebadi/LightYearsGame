// In the name of Allah

#pragma once

#include <cstdio>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

namespace LY {

    /** Giving smart pointers aliases, the power of this is not just shortening the code and definition but the
    ability to swap the smart pointer implementation. So if I find the standard smart pointers to be slow and I want
    to provide my own then I can easily change this alias and my code works. I don't need to search my whole code.
    **/
    template <typename T>
    using unique = std::unique_ptr<T>;

    template <typename T>
    using shared =  std::shared_ptr<T>;

    template <typename T>
    using weak = std::weak_ptr<T>;

    template <typename T>
    using List = std::vector<T>;

    template <typename keyType, typename valueType, typename Pr = std::less<keyType>>
    using Map = std::map<keyType, valueType, Pr>;

    template <typename keyType, typename valueType, typename Hasher = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valueType, Hasher>;

    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}
