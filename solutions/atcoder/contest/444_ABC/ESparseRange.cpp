#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    ll d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto& z:a) cin >> z;
    ll res = 0; 
    map<int,int> mp;
    set<int> st;
    int r = 0;

    auto chk = [&](int x) -> bool{
        if (st.size() == 0) return true;
        auto lb = st.lower_bound(x);
        if (lb != st.end()){
            if (abs(x - *lb) < d) return false;
        }

        if (lb != st.begin()){
            auto xx = prev(lb);
            if (abs(x - *xx) < d) return false;
        }
        return true;
    };

    for (int l = 0; l < n; l ++){
        while(r < n && chk(a[r])){
            int v = a[r];
            mp[v]++;
            if (mp[v]==1) st.insert(v);
            r++;
        }
        if (r>=l) res += (r - l);
        mp[a[l]]--;
        if (mp[a[l]] == 0) st.erase(a[l]);
    }

    cout << res << '\n';
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    cerr << " == END ==" << endl;
    return 0;
}
