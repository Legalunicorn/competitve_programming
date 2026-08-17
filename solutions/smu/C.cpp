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


// n = 2 
// or n = 52
//

void solve(){
    int n;
    cin >> n;
    if (n == 7){
        cout << "7 5 4 3 2 1 6" << endl;
        cout << "E E I L E B V" << endl;
        return;
    }
    vi ref;
    // ref = {13,1,3,5,7,9,11, 12 , 2 ,4 ,6 ,8 ,10};
    // ref = {13 ,3 ,1, 9, 5, 7, 11, 4, 6, 2, 12, 
    // ref = {12 ,3 , 1, 9, 5, 7,  11, }
    // for (int i = 0; i < 10; i++){
    //     for (int i = 1; i <= 13; i+=2) ref.pb(i);
    //     for (int i = 2; i <= 13; i+=2) ref.pb(i);
    // }
    // ref = {}
    // string s = "EBELIEV";
    // ref = {9, 11 ,13, 1, 3, 5, 7,   10, 12, 4, 2, 6, 8, 10};
    // ref = {9, 13, 1 ,3 ,5 ,7 , 11,  8, 12 , 2, 4, 6, 10  };
    // string s = "EEBELIV";
    string s = "BELIEVE";
    vi scam = {
        1,3,5,7,9,11,13,
        2,4,6,8,10,12,

        13, 1, 3, 5 ,7, 9, 11,
        12, 2, 4, 6, 8, 10, 

        11, 13, 1 , 3 ,5 ,7, 9,
        10 ,12 ,2 ,4 ,6 ,8,

        9, 11 ,13 ,1 ,3 ,5 ,7,
        8, 10, 12, 2, 4 ,6



    };
    for (int i = 0; i <= 10; i++){
        for (auto& z: scam) ref.pb(z);
    }
    vi b;
    vector<char> p;
    for (int i = 0; i < n; i++){
        int j = i % ref.size();
        b.pb(ref[j]);
        j = i % 7;
        p.pb(s[j]);
        // b.pb(ref.size() % i);
        // p.pb(s.size() % i);
    }

    debug(ref);
    debug(p);

    for (int i = 0; i < n; i ++){
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    for (int s = 0; s + 6 < n; s++){
        debug(s, s + 6);
        vector<pair<int, char>> z;
        for (int i = 0; i < 7; i++){
            z.pb({
                    b[s+i], p[s+i]
                    });
        }
        sort(all(z));
        debug(z);
        string xxx;
        for (int i = 0; i < 7;i++) xxx += z[i].S;
        debug(xxx);
    }
    // n == 52 
    //

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
