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

void solve(){
    int n;
    cin >>n;
    vi a(n);
    vi b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    vvi g(n, vi(4));
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (i-1>=0){
            g[i][0]+=a[i-1];
            g[i][2] = i-1;
        } else g[i][2] = -1;
        if (i+1<n){
            g[i][0]+=a[i+1];
            g[i][3] = i+1;
        } else g[i][3] = -1;
        g[i][1] = b[i];
    }
    vb dead(n);
    for (int i = 0; i < n; i++){
        if (g[i][0] > g[i][1]){
            q.push(i);
            dead[i] = true;
        }
    }
    // int rd = 1;
    // cout << q.size() << " ";
    debug(g);
    for (int rd = 0; rd < n; rd++){
        int len = q.size();
        cout << len << " ";
        int cnt = 0;
        debug("--------------");
        set<int> mb;
        for (int i = 0; i < len; i++){
            int id = q.front();
            q.pop();
            // already check if neighbours die too? 
            int l = g[id][2];
            int r = g[id][3];
            if (l != -1 && r != -1){
                g[l][0]+=(a[r]-a[id]);
                g[r][0]+=(a[l]-a[id]);
                g[r][2] = l;
                g[l][3] = r;
                if (g[l][0] > g[l][1] && !dead[l]) {
                    mb.insert(l);
                    // q.push(l);
                    // dead[l] = true;
                    // debug(l);
                }
                if (g[r][0] > g[r][1] && !dead[r]) {
                    mb.insert(r);
                    // q.push(r);
                    // dead[r] = true;
                    // debug(r);
                }
            } else if (l!=-1){
                g[l][0]-=a[id];
                g[l][3] = -1;
            } else if (r!=-1){
                g[r][0]-=a[id];
                g[r][2] = -1;
            }
            g[id][2] = g[id][3] = -1;
        }
        for (auto& x: mb){
            if (g[x][0] > g[x][1]){
                q.push(x);
                dead[x] = true;
            }
        }
    }
    cout << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
