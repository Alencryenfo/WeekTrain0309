//
// Created by guanghere on 25-3-9.
//
#include <iostream>
#include <vector>
#include <numeric>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1), times(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int lcm = 1;
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
        lcm = std::lcm(lcm, b[i]);
        if (lcm > 1e9) {
            std::cout << "No";
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] % b[j] != 0) {
                std::cout << "No\n";
                return 0;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     if (a[i] % lcm != 0) {
    //         std::cout << "No";
    //         return 0;
    //     }
    //     times[i] = a[i] / lcm;
    // }
    if (n == 1) {
        int lcm_b = b[1];
        for (int j = 2; j <= m; ++j) {
            lcm_b = std::lcm(lcm_b, b[j]);
            if (lcm_b > a[1]) {
                std::cout << "No\n";
                return 0;
            }
        }
        if (lcm_b == a[1]) {
            std::cout << "Yes\n";
            for (int j = 1; j <= m; ++j) {
                std::cout << b[j] << (j < m - 1 ? " " : "\n");
            }
        } else {
            std::cout << "No\n";
        }
    }
    else if (m == 1) {
        int gcd_a = a[1];
        for (int i = 2; i <= n; ++i) {
            gcd_a = std::gcd(gcd_a, a[i]);
        }
        if (gcd_a == b[1]) {
            std::cout << "Yes\n";
            for (int i = 1; i <= n; ++i) {
                std::cout << a[i] << "\n";
            }
        } else {
            std::cout << "No\n";
        }
    }

    std::cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == i % m) {
                std::cout << a[i] << ' ';
            } else {
                std::cout << b[j] << " ";
            }
        }
        std::cout << '\n';
    }
}