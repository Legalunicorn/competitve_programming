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
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//template/ template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // 
// template <class T> using ordered_multiset = tree<T, null_type,
// less_e

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
    I gave in and went to the solutions 
    there was two answer provided, one far more complicated with a DFS 
    DFS -> we assign blame and map it to a tree problem, then the answer is the 
    size of the subtree for each node. this pretty impressive idea, if the idea to model 
    this to a tree this would be a much harder problem 

    the alternative solution is first split east and north cows, then sort them 
    we sort them so that we can stop the right cows in order 
    the bottom left collision would stop cows, and so the future collisions can be skipped 
    then we build up the blame using a dp like solutoin dp[i] += (1 + dp[j])

*/
void solve(){
    int n;
    cin >> n;
    vi xpos(n), ypos(n);
    vi east,north;
    for (int i=0; i<n; i++){
        char dir;
        cin >> dir >> xpos[i] >> ypos[i];
        if (dir=='E') east.pb(i);
        else north.pb(i);                                                                                                                       
    }
    sort(all(east),[&](const int& a, const int& b){
            return ypos[a]<ypos[b];
    });
    sort(all(north),[&](const int& a, const int&b){return xpos[a]<xpos[b];});
    vl res(n,0); // infinite
    vb stop(n);
    for (auto r: east){
        for (auto u: north){
            if (stop[r] || stop[u]) continue;
            if (xpos[u] < xpos[r]) continue;
            if (ypos[r] < ypos[u]) continue;
            int utime = ypos[r] - ypos[u];
            int rtime = xpos[u] - xpos[r];
            if (utime == rtime) continue; //no collisions
            else if (utime < rtime){
                stop[r] = true;
                res[u] += (1 + res[r]);
            } else{
                stop[u] = true;
                res[r] += (1 + res[u]);
            }
        }
    }
    for (int r: res) cout << r  << endl;
};


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
