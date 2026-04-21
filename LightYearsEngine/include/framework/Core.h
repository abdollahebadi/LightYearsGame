// In the name of Allah

#pragma once

#include <cstdio>

namespace LY {
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}
