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




void solve(){
    int n;
    cin >> n;
    int odd = 0;
    int even1 = 0;
    int even2 = 0;
    map<int,int> mp;
    // vi a(2*n);
    for (int i=0;i<2*n;i++){
        int x; cin >> x;
        mp[x]++;
        // a[i] = x;
    }

    // sort(all(a));
    // debugv(a);

    for (const auto& [v,c]:mp){
        if (c%2==0) {
            int h = c/2;
            if (h%2==0) even1++; //e1 -> trouble split
            else even2++; //best 
        }
        else odd++; //confirm 1 
    }
    // cerr << odd << " " << even1 << " " << even2 << endl;
    int res =0 ;
    if (odd==0 && even2==0){
        res = (even1/2)*4;
        // cerr << "Y" << endl;
        cout << res << endl;
        return;
    }
    // if (odd==0 && even1==0)
    if (odd>0){
        res = odd + even1*2 + even2*2;
        cout << res << endl;
        return;
    }
    res = odd + even2*2 + (even1/2)*4;
    cout << res << endl;
    // res =
    // even1 -> goes in pairs
    //
    // if (odd>0){ // we create a 2 gap
    //     // 2 gap created if needed
    //     // filled by 
    //     res = odd + even1*2 + even2*2;
    // } else{
    //     res = odd;
    //     res += even2*2;



    // }

    // int res = even + 

    // int res = odd;  // dont need to think
    // cerr << odd << " " <<  even1 << " " << even2 << endl;


    // e1 + e2 -> forms 2 only!



    // // res += (even1/2)*4;
    // if (even1%2==1){
    //     if (even2>0) {
    //         cerr << "yes" << endl;
    //         res += 4;
    //         even2--;
    //     }
    // }
    // res += even2*2;
    // cout << res << endl;



    
    // if (even1%2==1) even1--;
    
    // cout << odd + even1 + even2 << endl;
    // cerr << odd << " " << even << endl;
    // cout << odd + even2 + (even1/2)*2 << endl;
    // the number of odd is always even 
    // cout << res << endl;

};

/*

if (even1)

*/


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