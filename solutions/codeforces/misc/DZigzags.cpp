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


// wait a second 
// we can is the middle two elements yes 
// a b c d 
// b and c iterat eall 
// then for each we want to count the number of c from [0,b]
// and the numer 

void solve(){
    int n;
    cin >> n;
    // vi tot(3001);
    vi a(n);
    for (int i=0;i<n;i++){
        int x; 
        cin >> x;
        a[i] = x;
        // tot[x]++;

    }
    ll res = 0;
    vvi pref(n,vi(3001)), suff(n,vi(3001));
    // pref[0][a[0]]++;
    for (int i=0;i<n;i++){
        pref[i][a[i]]++;
        suff[n-i-1][a[n-i-1]]++;

        

        // for (int v = 1; v <= )
    }
    for (int i=1;i<n;i++){
        for (int v = 0; v <= 3000; v++){
            pref[i][v] += pref[i-1][v];
            suff[n-i-1][v] += suff[n-i][v];
        }
    }

    for (int i=0;i<n;i++){
        cerr << pref[i][1] << " ";
    }
    cerr << endl;
    for (int i = n-1; i>=0; i--) cerr << suff[i][1] << " ";
    cerr << endl;

    for (int b = 1; b+2<n; b++){
        for (int c = b+1; c+1 < n; c++){
            ll left = (ll) pref[b-1][a[c]];
            ll right = (ll) suff[c+1][a[b]];
            res += left * right;
        }
    }
    cout << res << endl;

    // vi freq(3001);
    // ll res = 0;
    // // tot[a[0]]--; // can ignore 
    // // this solution is stupid bro 
    // // checking the most recent number only makes no sense 
    // // you need to check the older numbers too ! 
    // // notice the constraints that a[i] < n 
    // // instead of position we can try searching by value 
    // // i = MAX, j = MAX until min 
    // //
    // for (int i = 0; i<n-3;i++){
    //     tot[a[i]]--;
    //     freq.assign(3001,0);
    //     for (int x =i+1; x<n-2; x++){
    //         freq[a[x]]++;
    //         if (a[x+1] != a[i])  continue;
    //         ll left = (ll)freq[a[x]];
    //         ll right = tot[a[x]] - freq[a[x]];
    //         if (a[x+1] == a[x]) right--;
    //         cerr << i << " " << x << endl;
    //         cerr << left << ":" << right << endl << endl;
    //         res += left * right;
    //     }
    // }
    
    // cout << res << endl;
    // cerr << endl;
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
