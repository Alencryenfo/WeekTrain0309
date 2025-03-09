//
// Created by 26444 on 25-3-9.
//
// guanghere
#include <cmath>
#include <format>
#include <iostream>

using ull = unsigned long long;
constexpr ull mod = 998244353;

ull quick_pow(ull x, int y) {
    ull res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    ull ans = 0;
    for (ull i = 1; i <= n - 1; i++) {
        ans += i * i % mod *
               (n - i) % mod * (quick_pow(i + 1, m) - 2 * quick_pow(i, m) +
                       quick_pow(i - 1, m) + 2 * mod) % mod;
        ans %= mod;
    }
    std::cout << ans << std::endl;
}
