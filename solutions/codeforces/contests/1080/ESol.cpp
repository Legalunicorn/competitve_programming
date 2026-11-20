
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
	vector<array<int, 2>> a(n);
	for (auto& v : a) {
		for (int& x : v) {
			x = nxt() - 1;
		}
	}
	vector<int> order;
	auto dfs = [&](auto self, int v) -> void {
		for (int x : a[v]) {
			if (x != -1) {
				self(self, x);
			}
		}
		order.push_back(v);
	};
	dfs(dfs, 0);
	vector<int> sz(n, 1);
	for (int i : order) {
		for (int j : a[i]) {
			if (j > -1) {
				sz[i] += sz[j];
			}
		}
	}
	reverse(all(order));
	vector<long long> res(n);
	for (int i : order) {
		res[i] += 2 * sz[i] - 1;
		for (int j : a[i]) {
			if (j > -1) {
				res[j] = res[i];
			}
		}
	}
	for (auto x : res) {
		cout << x % 1000000007 << " ";
	}
	cout << "\n";
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

