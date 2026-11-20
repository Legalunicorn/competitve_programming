#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << 1 << "\n"; // number of test cases

    // seed from command line argument
    int seed = atoi(argv[1]);
    mt19937 rng(seed);

    // generate n in [1, 20]
    uniform_int_distribution<int> distN(1, 20);
    int n = distN(rng);

    // generate permutation
    vi p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);

    // generate l, r in [0, n]
    uniform_int_distribution<int> distLR(0, n);
    int l = distLR(rng);
    int r = distLR(rng);

    while (r == l) r = distLR(rng);
    if (l > r) swap(l, r);

    cout << n << " " << l << " " << r << "\n";
    for (int x : p) cout << x << " ";
    cout << "\n\n";

    return 0;
}
