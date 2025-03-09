#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    // Step 1: Check divisibility
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] % b[j] != 0) {
                cout << "No\n";
                return 0;
            }
        }
    }
    // Step 2: n = 1
    if (n == 1) {
        ll lcm_b = b[0];
        for (int j = 1; j < m; ++j) {
            lcm_b = lcm(lcm_b, b[j]);
            if (lcm_b > a[0]) { // Early exit if LCM exceeds a[0]
                cout << "No\n";
                return 0;
            }
        }
        if (lcm_b == a[0]) {
            cout << "Yes\n";
            for (int j = 0; j < m; ++j) {
                cout << b[j] << (j < m - 1 ? " " : "\n");
            }
        } else {
            cout << "No\n";
        }
    }
    // Step 3: m = 1
    else if (m == 1) {
        ll gcd_a = a[0];
        for (int i = 1; i < n; ++i) {
            gcd_a = gcd(gcd_a, a[i]);
        }
        if (gcd_a == b[0]) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\n";
            }
        } else {
            cout << "No\n";
        }
    }
    // Step 4: General case
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == i % m) {
                    cout << a[i];
                } else {
                    cout << b[j];
                }
                cout << (j < m - 1 ? " " : "\n");
            }
        }
    }
    return 0;
}