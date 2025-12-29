/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;
using vvb = vector<vb>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244353;
constexpr double PI = 3.14159265358979323846;


// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define sortU (a) sort(all(a)),(a).erase(unique(all(a)),(a).end())

// === Debug macros , to add a general function and replace this gunk
#define debugv(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const vector<char> dir_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}

/*
 * if we sum the number of balls 
 * it should tell me who it ends on ? 
 *
*/

ll fac[60];
ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}

ll inverse(ll num){
    return binpowmod(num,MOD-2,MOD);
}

ll ncr_mine(int n, int k){
    return fac[n] * inverse(fac[k]*fac[n-k] % MOD) % MOD;
}



void start(){
    fac[0] = 1;
    fac[1] = 1;
    fac[2] = 2;
    for (int x = 3; x <= 55; x++){
        fac[x] = (fac[x-1] * x % MOD);
    }
}

int tc = 0;

void solve(){
    int n;
    cin >> n;
    vl a(n+1);
    for (auto& z:a) cin >> z;

    ll sum =0;
    for (auto& x:a) sum += x;
    ll mod = sum % n; // mod is how many "sticks out"
    ll rounds = sum/n;  // no one can exceed round+1 

    for (int i =1; i<n+1;i++){
        int x = a[i];
        if (mod==0){
            if (x > rounds){
                cout << 0 << endl;
                return;
            }
        } else {
            if (x > rounds+1){
                cout << 0 << endl;
                return;
            }
        }
    }
    // all permuatateoin 
    if (mod==0){
        cout << fac[n] << endl;
        return;
    }

    ll cnt = 0;
    ll lim = mod;
    for (int i=1;i<n+1;i++){
        if (a[i] == rounds+1){
            cnt++;
            if (cnt > lim){
                cout << 0 << endl;
                return;
            }
        }
    }

    // ll base = (ll)(lim - cnt);
    if (cnt == lim){ // we just have the permutate those within 
        // cerr << "ok!" << endl;
        // debugv(a);
        ll val = (fac[cnt] * fac[(n-cnt)]) % MOD;
        cout << val << endl;
        return;
    }
    if (cnt==0){
        ll val = fac[n];
        cout << val << endl;
        return;
    }
    ll base = (ll)(lim - cnt);
    ll val = fac[n-cnt] * fac[lim] * inverse(fac[lim-cnt]) % MOD;
    cout << val << endl;
    
};

/*
 
   there can be empty number of decorations 

   we must use all the decorations 

*/



int main(){
    // ll INV = binpowmod(ll a, ll b, ll m)
    start();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
