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

int tc = 0;
bool found = false;
void solve(){
    // cerr << endl;
    tc++;
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    int count = 0;
    vi a(n);
    // i -> pointer for target 
    // j -> pointer for source 
    for (int i = n-1, j = n-1; i>=0; i--){
        // find the starting element for s[j]
        while(j >=0 && t[i] != s[j]){
            j--;
        }
        // impossuble case 
        if (j<0) count = k+10;
        else count = max(count,(i-j)); // max distance we have to pull 
        a[i] = j; // the position we need 
        if (i==j) j--; // the default decremenet of j, but only act if j did not move earlier 
    }
    // answer is too large 
    if (count > k){
        cout << -1 << endl;
        return;
    }
    cout << count << endl;
    vector<string> res(count,s);
    // back to front each element 
    for (int j = n-1; j >= 0; j --){
        int cnt = count - 1;
        // start from here, and go backwards to the position that is needed 
        for (int i=j; i > a[j]; i--){
            res[cnt][i] = t[j];
            cnt--;
        }
    }
    // how did i miss that 
    // i had the idea to find the back positiion sure 
    // res[cnt][i] means 
    for (auto& x: res) cout << x << endl;


    // if (tc==1 && t == "aizlqtbtevuteewmnotvldspvd") found = true;
    // if (tc==340 && found){
    //     string dd = to_string(n)+":"+to_string(k)+":"+s+":"+t;
    //     cout << dd << endl;
    //     return;
    // }
    // if (s[0] != t[0]){
    //     cout << -1 << endl;
    //     return;
    // }
    // vector<string> res;
    // vi last(26, -1);
    // vi delta(n, 0);
    //
    // auto comp = [&]() -> bool{
    //     delta.assign(n,0);
    //     last.assign(26,-1);
    //     last[t[0]-'a'] = 0;
    //     for (int i = 1; i<n; i++){
    //         last[s[i]-'a'] = i;
    //         int w = t[i] - 'a';
    //         if (last[w] == -1){
    //             cerr << "oops" << i << endl;
    //             cerr << s << endl;
    //             cerr << t << endl;
    //             return false;
    //         } else{
    //             int dist = i - last[w];
    //             if (dist == -1){
    //                 cerr << last[w] << " " << i << endl;
    //             }
    //             delta[i] = dist;
    //         }
    //     }
    //     return true;
    // };
    //
    // int changes = 0; 
    // for (int op =0; op<k; op++){
    //     int changes = 0;
    //     last.assign(26,-1);
    //     delta.assing(n,0);
    //
    //     // bool evl = comp();
    //     // debugv(delta);
    //     // if (!evl){
    //     //     for (auto& x: res) cerr << x << endl;
    //     //     cerr << "fatal " << endl;
    //     //     cout << -1 << endl;
    //     //     return;
    //     // }
    //     // changes = 0;
    //     // int left = n;
    //     // for (int i = n-1; i>0; i--){
    //     //     if (delta[i] !=0) left = min(left, i - delta[i]+1);
    //     //     if (delta[i] !=0 || i >= left){
    //     //         s[i] = s[i-1];
    //     //         if (s[i] != t[i]){
    //     //
    //     //         }
    //     //         changes++;
    //     //     }
    //     // }
    //     // if (changes == 0) break;
    //     // else res.pb(s);
    // }
    // if (res.size()>k  || (res.size()>0 && res[res.size()-1] != t)){
    //     cerr << tc <<  "too slow " << endl;
    //     cerr << res.size() << endl;
    //     for (auto&z: res) cerr << z << endl;
    //     cout << -1 << endl;
    // } else{
    //     // cerr << "good" << endl;
    //     cout << res.size() << endl;
    //     for (auto& z: res) cout << z << endl;
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
