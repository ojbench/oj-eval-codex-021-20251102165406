#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m, s;
    if (!(cin >> k)) return 0;
    if (!(cin >> n)) return 0;
    if (!(cin >> m)) return 0;
    if (!(cin >> s)) return 0;

    // Read the brick colors (2n lines, each with 2n numbers)
    // Colors are not used in this baseline strategy.
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            int c; cin >> c; (void)c;
        }
    }

    // Baseline control policy:
    // - On the first bottom touch, set horizontal velocity to +2 (operation 'E').
    // - For all subsequent touches (up to m in total), keep velocity unchanged ('C').
    // This yields a constant |vx| = 2 trajectory which tends to traverse
    // many columns due to wall reflections, providing a reasonable baseline.

    if (m <= 0) return 0;
    cout << 'E' << '\n';
    for (int i = 1; i < m; ++i) cout << 'C' << '\n';
    return 0;
}

