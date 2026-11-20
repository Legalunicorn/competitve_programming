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

// #define endl '\n' 
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

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

void solve(){
    int n,m;
    cin >> n >> m;
    string s; cin >> s;
    __int128 k = 0;
    for (char c:s){
        k = k * 10 + (c -'0');
    }
    vector<string> g(n);
    for (auto& z:g) cin >> z;
    // auto go = [&](auto& go, int i, int j) -> void{
    //     seen[i][j] = true;
    //     for (auto& d: dirs){
    //         int x = i+ d[0], y = i + d[1];
    //         if (x < 0 || x >= n || y < 0 || y >= m || (g[i][j] != '.' && g[i][j] !+ ''))
    //     }
    // }
    __int128 cnt = 1;


    debug(g);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '@'){

            }
            if (g[i][j] =='.') cnt++;
        }
    }
    cnt *=  k;
    // cout << "Your destination will arrive in ";
    printf("Your destination will arrive in ");
    print(cnt);
    printf(" meters");
    // cout << " meters";
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
