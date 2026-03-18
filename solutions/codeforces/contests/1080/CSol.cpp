#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = nxt();
    vector<int> a(n);
    generate(all(a), nxt);
    int ans = 0;
    int cur = 0;
    int last = -1;
    for (int x : a) {
        if (x != 7 - last && x != last) {
            ans += cur / 2;
            cur = 0;
        }
        ++cur;
        last = x;
    }
    ans += cur / 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}

