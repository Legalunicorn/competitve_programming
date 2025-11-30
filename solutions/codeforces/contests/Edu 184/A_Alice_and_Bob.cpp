#include <bits/stdc++.h>
// #include "gurgerbrill.h"

using namespace std;
#define int long long
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    int a; cin >> a;
    int ab = 0, bc = n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < a) ab++, bc --;
        if (v[i] == a) bc--;
    }
    // if (ab == 0 && bc == 0) cout << 1; 
    if (ab >= bc) cout << a - 1;
    else cout << a + 1;
    cout << endl;
}

signed main(){
    int t = 1;
    cin >> t;
    while (t--) solve();
}

