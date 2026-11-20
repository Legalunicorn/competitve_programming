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
    char a,b;
    int x,y;
    cin >> a >> x >> b >> y;
    // must be the same pairtiy 
    int s1 = x + (a - 'A');
    int s2 = y + (b - 'A');
    debug(s1,s2);
    if (s1 % 2 != s2  % 2){
        cout << "Impossible" << endl;
        return;
    }
    if (x == y && a == b){
        cout << 0 << " " << a << " " << x << endl;
        return;
    }


    pi one,two;
    one.F = (a - 'A') + 1;
    one.S = x;

    two.F = (b- 'A') + 1;
    two.S = y;

    int dx = abs(one.F - two.F);
    int dy = abs(one.S - two.S);
    if (dx == dy){
        cout << 1 << " " << a << " " << x << " " << b << " " << y << endl;
        return;
    }

    for (int r = 1; r <= 8; r++){
        for (int c = 1; c <= 8; c++){
            pi done;
            pi dtwo;
            done.F = abs(one.F - c);
            done.S = abs(one.S - r);
            dtwo.F = abs(two.F - c);
            dtwo.S = abs(two.S - r);
            if (done.F == done.S && dtwo.F == dtwo.S){
                cout << 2 << " " <<  a << " " << x << " ";
                char go = (char)(c - 1 + 'A');
                cout << go << " " << r << " ";
                cout << b << " " << y << endl;
                return;
            }

        }
    }

    debug(one,two);



    // int r1 = a - 'A' + 1;
    // int r2 = b - 'A' + 1;
    //
    //
    // int d1 = abs(r1 - r2);
    // int d2 = abs(x - y);
    // if (d1 == d2) {
    //     cout << 1  << " "<< a << " " << x << " " <<  b << " " << y << endl;
    // }
    //
    // debug(x,r1);
    // debug(y,r2)
    //
    // // two moves just find any on the boored;
    // for (int r = 1; r <= 8; r++){
    //     for (int c = 1; c <= 8; c++){
    //         int p1 = abs(r1 - r);
    //         int p2 = abs(x - c);
    //         int p3 = abs(r2 - r);
    //         int p4 = abs(y - c);
    //
    //         if (p1 == p2 && p3 == p4){
    //             debug(p1,p2,p3,p4);
    //             // {r,c} is valid!! 
    //             char cc = (char)((r-1) + 'A');
    //             int pp = r;
    //             debug(cc, pp, c , r);
    //             cout << 2 << " " <<  a << " " << x;
    //             cout << " " << cc << " " << pp;
    //             cout << " " << b << " " << y;
    //             cout << endl;
    //             return;
    //         }
    //     }
    // }

    // handle direct move case 

    // find a common cell within bounds 
    // there is two intersections 
    // one is within bounds 
    // they could also be on the same diagonoal 

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
