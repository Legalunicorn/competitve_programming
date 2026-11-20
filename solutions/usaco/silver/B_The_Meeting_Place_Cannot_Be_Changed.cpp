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


/*
coordinate compression dont quite work
with long double...


i should figure out another way perhaps?.
how to find if all interval has a common value
maintain max and min? 
the
*/
bool check(vl& a, vl& b, ld T){

    // map<ld,int> mp;
    // set<ld> vals;
    int n = a.size();
    ld mn = (ld)(-1);
    ld mx = (ld)(INF);
    for (int i=0; i<n;i++){
        ld x = (ld)a[i];
        ld left = x-(T*b[i]);
        ld right = x+(T*b[i]);

        mn = max(mn,left);
        mx = min(mx,right);
        // vals.insert(left);
        // vals.insert(right);
    }
    // cerr << mn << " "  << mx << endl;
    return mn<=mx;
    // cerr << "t: " << T  << endl;
    // int id = 0;
    // for (const auto& s: vals){
    //     cerr << to_string(s) << "  ";
    //     mp[s]=id++;
    // }
    // cerr << endl;
    // vi nodes(id+1);
    // for (int i=0; i<n;i++){
    //     ld x = (ld)a[i];
    //     ld left = x-T;
    //     ld right = x+T;
    //     nodes[mp[left]]++;
    //     nodes[mp[right]+1]--;
    // }
    // int tot = nodes[0];
    // for (int i=1;i <(id+1); i++){
    //     nodes[i] += nodes[i-1];
    //     if (nodes[i]==n) return true;
    // }
    // return false;
};

void solve(){
    int n;
    cin >> n;
    vl a(n),b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    ld l = 0, r = (ld)MAX(a);
    ld res = r;
    while((r-l)>=0.0000001){
        ld mid = l+(r-l)/2;
        if (check(a,b,mid)){
            res = mid;
            r = mid- 0.0000001;
        } else l = mid + 0.0000001;
    }
    cout << to_string(res) << endl;
};
/*
1. binarch search over T
2. coordinate compression for each K



------
1. we have to find the optimal point where everyone can meet
2. we have to find the max time for everyone to reach said point 

lets say we try by time K
-> if all the intervals intersect at some common point, then its possible

-> coordinate compression maybe? 

1. for every person generate 2 end points
2. compress into a differen array
3. find any position in the difference array equals to n

as for the binary search, we need accuracy of 10e-6,

l<=r
(r-l<=0.0000001)
should work, hopefully not tle 


*/


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
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