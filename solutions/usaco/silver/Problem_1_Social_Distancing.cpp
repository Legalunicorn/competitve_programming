/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */
#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
constexpr ll MOD = 1e9+7;
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



bool check(vpl& a, ll d, int n){
    // i -> n couunter
    // j -> interval counter? 
    int j = 0, i =0; //current inteverla
    ll bound = -1;
    // cerr << d << " : " << endl;
    while(i<n){
        pl& curr = a[j];
        if (bound<=curr.F){
            i++;
            // place a cow at curr.F 
            // cerr << curr.F <<  ".  ";
            bound = curr.F + d;
        } else if (bound<=curr.S){
            // place a cow at bound
            i++;
            // cerr << bound <<  ",  ";
            bound += d;
        } else{ // this interval cannot be used
            j++;
        }
        if (j>=a.size()) return false;
    }
    
    return true;

}

void solve(){
    int n,m;
    cin >> n >> m;
    vpl a(m);
    for (int i=-0;i<m;i++){
        ll x,y; cin >> x >> y;
        a[i] = {x,y};
    }
    auto cmp = [](const auto& p, const auto& q){
        return p.F<q.F;
    };
    sort(all(a),cmp);
    // for (const auto& x: a){
    //     cerr << x.F << " " << x.S << endl;
    // }
    ll res = 1;
    ll l = 1, r = INF;
    while(l<=r){
        ll m = l + (r-l)/2;
        bool v = check(a,m,n);
        // cerr << endl;
        if (v){
            res = m;
            l = m + 1;
        } else r = m -1;
    }
    cout << res << endl;
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}