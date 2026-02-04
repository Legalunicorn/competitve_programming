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




vector<int> factor(int n){
    vector<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if (n>1) res.push_back(n);
    return res;
}


void solve(){
    int n;
    cin >> n;
    string a = "Ashishgup", b ="FastestFinger";
    if (n == 1){
        cout << b << endl;
        return;
    } else if (n==2){
        cout << a << endl;
        return;
    } else{
        // who ever receives "1" dies 
        // if you are forced to give "2" to your opponent you also die 
        //
        if (n%2==1){
            cout << a << endl;
        } else{
            // even case 
            vi fac = factor(n);
            bool has_odd = false;
            for (auto& f: fac) if (f%2==1) has_odd = true;
            if (!has_odd){
                cout << b << endl;
                return;
            }
            // all even factors...
            if (fac.size() ==2 ){
                //gg 
                cout << b << endl;
            } else{
                cout << a << endl;
            }
        }
    }

    // odd divisors?... isnt any odd number a divsisor 
    // so if x is ODD, we win instantly 
    // if x is even, we must either -1 or choose some odd divisor 
    // 3 * 4 = 12 
    // 3 * 3 = 9 
    // 3 * 2 = 6 
    //
    // odd * even = even 
    // odd * odd = odd 
    // 
    // EVEN case 
    // -> we cannot minus 1, instant lose 
    // -> we must divide by some odd factor 
    // then it becomes a game of who can keep dividing 
    // since odd * odd = odd 
    // cant we just divide by all the product of odd divisors 
    // then the next ture 
    // if x is EVEN, dividing by odd -> EVEN 

    // n -> 10e9 
    // x = 2, this player wins
    // x = 3, this player wins 
    // x = 4, -> reduce to 3, LOSE 
    // x = 5 -> 
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
