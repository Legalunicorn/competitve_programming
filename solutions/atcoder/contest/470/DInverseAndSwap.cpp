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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE: 
// we must track in terms of cycles? 
// what is a swap? 
// what is a new P? 
//
// the cycles themselves are in groups 
// ifwe just spam 2 the cycles shift. 
//
// we need some data structure to maintain the "cycles"
//
// how destructive is operation1 ? 
// actually it doesnt really make much of a difference? 
// 1) both are different grounds then its just a normal swap in the position for each group 
//
// 2) both are in the same cycle -> then we just swap their positions 
//
// then at the end we need to count how many query 2s were there, and for each cycle offset the start by some math mod bull shit 
//
//
// map<int, vector<int>>   ==> store cycles as a seuqnece of numbers 
// map<int, map<int,int>> ==> store the position instead 
// 




void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for (auto& z:a) cin >> z;
    for (int i = 0; i < n; i++) a[i]--;
    vi front(n), back(n);
    // map<int,
    for (int i = 0; i < n; i++){
        int j = a[i];
        front[a[i]] = j;
        back[j] = a[i];
    }
    int cnt = 0;
    while(q--){
        int id,x,y;
        cin >> id;
        if (id == 2) cnt++;
        else{
            cin >> x >> y;
            x--,y--;
            swap(front[x], front[y]);
        }
    }
    vi ans(n);
    vb seen(n, false);
    vl temp;
    for (int i = 0; i < n; i ++){
        int c= i;
        // if (!seen[c]) temp.clear();
        while(!seen[c]){
            temp.pb(c);
            seen[c] = true;
            c = a[c];
        }
        if (temp.size() > 0){
            debug(temp);
            int m = temp.size();
            int s = cnt % m;
            for (int i = 0; i < m; i++){
                int u = temp[i];
                ans[u] = temp[(u+s)%m]+1;
            }
            temp.clear();
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
