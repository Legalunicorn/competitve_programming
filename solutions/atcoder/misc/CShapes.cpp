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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int n;
    cin >> n;
    using vvc = vector<vector<char>>;
    using vc = vector<char>;
    vector<vector<char>> s(n, vector<char>(n)), t(n, vector<char>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cin >> s[i][j];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cin >> t[i][j];
    }

    auto flip = [&](vvc& a) -> void{
        for (int i =0;i<n;i++){
            for (int j =0; j<n/2;j++){
                swap(a[i][j], a[i][n - 1 - j]);
            }
        }
    };

    auto trans = [&](vvc & a) -> void{
        for (int i=0;i<n;i++){
            for (int j = 0; j < i; j++){
                swap(a[i][j], a[j][i]);
            }
        }
    };

    auto rotate = [&](vvc& a)->void{
        flip(a);
        trans(a);
    };

    vvb seen(n, vb(n,false)), seen2(n,vb(n,false));


    for (int i = 0; i < 5; i++){
        rotate(t);
        array<int,4> one,two;
        one = {n,-1,n,-1};
        two = {n,-1,n,-1};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n ; j++){
                if (s[i][j] == '#'){
                    one[0] = min(one[0],i);
                    one[1] = max(one[1],i);
                    one[2] = min(one[2],j);
                    one[3] = max(one[3],j);
                } 
                if (t[i][j] =='#'){
                    two[0] = min(two[0],i);
                    two[1] = max(two[1],i);
                    two[2] = min(two[2],j);
                    two[3] = max(two[3],j);
                }
            }
        }
        if (one[1] - one[0] != two[1] - two[0] || one[3]-one[2] != two[3] - two[2]){
            continue;
        }

        int x = one[1] - one[0];
        int y = one[3] - one[2];
        bool valid = true;
        for (int r = 0; r < x ; r++){
            for (int c = 0; c < y ; c++){
                char c1 = s[r+one[0]][c+one[2]] ;
                char c2 = t[r+two[0]][c+two[2]];
                if (c1!=c2) valid = false;
            }
        }
        if (valid){
            cout << "Yes" << endl;
            return;
        }

    }
    cout << "No" << endl;
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
