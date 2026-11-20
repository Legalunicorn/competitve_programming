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


string g[3];
bool check2( char a, char b){
    for (int i=0;i<3;i++){
        // bool f = true;
        int x = 0; 
        int y = 0;
        for (char c: g[i]){
            if (c==a) x++;
            if (c==b) y++;
        }
        if ((x+y==3 || x+y==6) && x>0 && y>0) return true;

        x = 0;
        y = 0;
        for (int j=0;j<3;j++){
            char c = g[j][i];
            if (c==a) x++;
            if (c==b) y++;
        } 
        if ((x+y==3 || x+y==6) && x>0 && y>0) return true;
    }
    int x = 0, y= 0;
    if (g[0][0]==a) x++;
    if (g[0][0]==b) y++;
    if (g[1][1]==a) x++;
    if (g[1][1]==b) y++;
    if (g[2][2]==a) x++;
    if (g[2][2]==b) y++;
    if ((x+y==3 || x+y==6) && x>0 && y>0) return true;

    x = 0, y = 0;
    if (g[0][2]==a) x++;
    if (g[0][2]==b) y++;
    if (g[1][1]==a) x++;
    if (g[1][1]==b) y++;
    if (g[2][0]==a) x++;
    if (g[2][0]==b) y++;
    if ((x+y==3 || x+y==6) && x>0 && y>0) return true;   
    return false;

};

bool check(char c){
    return check2(c,c);
};

void solve(){
    for (int i=0;i<3;i++) cin >> g[i];
    // map<char,int> lines[8];
    // for (int i=0;i<3;i++){
    //     char (char c: g[i]) lines[]
    // }
    int one  = 0, two = 0;

    // single cows
    for (int i=0;i<26;i++){
        // cerr << i << endl;
        char c = (char)(i+'A');
        if (check(c)) {
            // cerr << c << "::" << endl;
            one++;
        }

        for (int j = i+1; j<26;j++){
            char v = (char)(j+'A');
            if (check2(c,v)){
                // cerr << c << " : " << v << endl;
                 two++;
            }
        }
    }
    cout << one << endl;
    cout << two << endl;
    // cout << one << " " << two << endl;




};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);


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