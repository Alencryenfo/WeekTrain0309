//
// Created by 26444 on 25-3-9.
//
// guanghere
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
    if (m == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    ull ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += i * i *
               (n - i) * (quick_pow(i + 1, m) - 2 * quick_pow(i, m) +
                       quick_pow(i - 1, m) + 100 * mod);

        //ans += (n - i) * m * (m - 1) * quick_pow(i + 1, m - 2) * i * i;
        ans %= mod;
    }
    // for (int b = 1; b <= n; b++) {
    //     for (int a = b; a <= n; a++) {
    //         ull contribution = (a - b) * (a - b) * quick_pow(a - b + 1, m -
    //         2); ans += contribution; ans %= mod; std::cerr << std::format("a
    //         = {}, b = {}, contribution = {}\n", a, b, contribution);
    //     }
    // }
    std::cout << ans << std::endl;
}
