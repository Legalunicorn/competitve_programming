#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    int k,n;
    cin >> k >> n;
    vector<string> a(k);
    for (auto& s: a) cin >> s;
    sort(all(a));
    if (a.front() == a.back()){
        string s = a.front();
        swap(s[0], s[1]);
        cout << s << endl;
        return;
    }
    string x = a.front(), y = a.back();
    debug(a);
    auto same = [&](string& t) -> bool{
        int freq[26] = {};
        for (char c: t){
            freq[c-'a']++;
            if (freq[c-'a'] > 1) return true;
        }
        return false;
    };
    auto check = [&](string& s) -> bool{
        bool dd = same(s);
        for (string v: a){
            int diff = 0, one = -1, two = -1;
            for (int c = 0; c < n; c++){
                if (s[c] != v[c]){
                    diff++;
                    if (diff > 2) return false;
                    else if (diff == 1) one = c;
                    else two = c;
                }
            }
            if (diff == 0){
                if (!dd) return false;
            }
            else if (diff == 2){
                if (v[one]!=s[two] || v[two] != s[one]) return false;
            } else return false;
        }
        return true;
    };
    vi pos;
    for(int i = 0;i < n; i++){
        if (x[i] != y[i]) pos.pb(i);
    }
    debug(x,y,pos);
    if (pos.size()>4){
        cout << -1 << endl;
        return;
    }
    for (int id = 0; id < k; id++) {
        for (int i : pos) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                string s = a[id];
                swap(s[i], s[j]);
                if (check(s)) { cout << s << endl; return; }
            }
        }
    }
    // for (int id: {0, k-1}){
    //     for (int i: pos){
    //         for (int j = 0; j < n; j++){
    //             if (i==j) continue;
    //             swap(a[id][i], a[id][j]);
    //             string s = a[id];
    //             if (check(s)){
    //                 cout << s << endl;
    //                 return;
    //             }
    //             swap(a[id][i], a[id][j]);
    //         }
    //     }
    // }
    cout << -1 << endl;

    // vi freq(26);
    // for (auto& s:a) cin >> s;
    // set<string> st(all(a));
    // if (st.size() == 1){
    //     string s = a[0];
    //     swap(s[0], s[1]);
    //     cout << s << endl;
    //     return;
    // }
    // sort(all(a));
    // bool same = false;
    // for (char c: a[0]){
    //     freq[c-'a']++;
    //     if (freq[c-'a'] > 1) same = true;
    // }
    // vi pos;
    // debug(st);
    // string x= a.front();
    // string y= a.back();
    // debug(x);
    // debug(y);
    // for (int i = 0; i < n; i++){
    //     if (x[i] != y[i]){
    //         pos.pb(i);
    //     }
    // }
    // if (pos.size() > 4){
    //     cout << -1 << endl;
    //     return;
    // }
    // debug(pos);
    // debug(same);
    // for (int i: pos){
    //     for (int j = 0 ; j < n; j++){
    //         string s = a[0];
    //         bool valid = true;
    //         swap(s[i], s[j]);
    //         debug(s);
    //         for (int id = 1 ; id < k; id++){
    //             if (!valid) break;
    //             int diff = 0;
    //             int one = -1, two = -1;
    //             for (int c = 0; c < n; c++){
    //                 if (s[c] != a[id][c]){
    //                     diff++;
    //                     if (diff > 2){
    //                         valid = false;
    //                         break;
    //                     }
    //                     if (diff == 1) one = c;
    //                     else two = c;
    //                 }
    //             }
    //             debug(diff);
    //             if (diff == 0){
    //                 if (!same){
    //                     valid = false;
    //                     break;
    //                 }
    //             } else if (diff == 2){
    //                 if (s[one] != a[id][two] ||  s[two] != a[id][one]){
    //                     valid = false;
    //                     break;
    //                 }
    //             } else valid = false;
    //         }
    //         if (valid){
    //             cout << s << endl;
    //             return;
    //         }
    //         swap(s[i], s[j]);
    //     }
    // }
    // cout << -1 << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
