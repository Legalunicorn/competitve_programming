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


// 4 3 2 5 6 
// 2 1 1 2 3 
// maybe we only care about numbers that are FORCED odd all the way 
// 1 3 7 15 31 
// vs 
// 1 2 4 9 19 
// .... if we do +1, the guy can deal with OTHER odds 
// maybe we just skip +1 all together 
// and sum them separately 
void solve(){
    int n,q; 
    cin >> n >> q;
    vi a(n), odd(n), cnt(n);
    // a -> totla moves 
    // odd(n) -> is odd 
    // cnt(n) -> count_odd/2 gives extra but we have the chance to void extra some how 
    // but doing "in a rows" 
    for (int i=0;i<n;i++){
        int x; cin >> x;
        if (x%2==1) odd[i] ++;
        int t = 0, st = 0;
        bool streak = true;
        while(x>1){
            t++;
            x /=2;
            if (x==1) break;
            if (streak && x%2==1){
                st++;
                x++;
            }
        }

    }
    


    // for (int i=0;i<n;i++){
    //     int x; cin >> x;
    //     if (x%2==1) odd[i] = 1;
    //     int t = 0, op = 0;
    //     // maybe its just the sum of odds divided by two or something like that 
    //     while(x>1){
    //         if (x%2==1) op++;
    //         x /=2;
    //         t++;
    //         // if (x == 1) break;
    //         // if (x %2==1) op++;
    //     }
    //     opp[i] = op;
    //     a[i] = t; // count 
    // }
    // debugv(a);
    // debugv(opp);
    // for (int i=1;i<n;i++){
    //     a[i] += a[i-1];
    //     opp[i] += opp[i-1];
    // }
    // debugv(a);
    // debugv(opp);
    // // precompute answers 
    // while(q--){
    //     int l,r; 
    //     cin >> l >> r, l--, r--;
    //     ll sum = a[r] - (l>0? a[l-1]:0);
    //     int o = opp[r] - (l>0? opp[l-1]:0);
    //     sum += (o/2);
    //     cout << sum << endl;
    // }
    
};


int main(){

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
