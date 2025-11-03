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

    // Heuristic control policy:
    // Maintain and cycle the horizontal speed magnitude through a pattern
    // to diversify trajectories and cover more bricks than a single slope.
    // We do not simulate physics here; we only track |vx| changes we apply.

    if (m <= 0) return 0;

    // Desired magnitude cycle (repeat): ramp up and down modestly
    static const int cycle_vals[] = {1,2,3,4,5,6,7,6,5,4,3,2};
    const int L = (int)(sizeof(cycle_vals)/sizeof(cycle_vals[0]));

    int mag = 0; // current |vx| magnitude we control via ops
    auto emit = [&](int delta){
        char op;
        if (delta <= -2) { op = 'A'; delta = -2; }
        else if (delta == -1) { op = 'B'; }
        else if (delta == 0) { op = 'C'; }
        else if (delta == 1) { op = 'D'; }
        else /* delta >= 2 */ { op = 'E'; delta = 2; }
        cout << op << '\n';
        mag += delta;
    };

    // First step: move to 2 quickly
    emit(2);
    for (int i = 1; i < m; ++i) {
        int target = cycle_vals[i % L];
        int delta = target - mag;
        emit(delta);
    }
    return 0;
}
