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
    int val = 0;
    // bes
    vector<string> animals = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string,int> id, year, sign;
    year["Bessie"] = 0;
    sign["Bessie"] = 0; //id
    for (int i=0;i<12;i++) id[animals[i]] = i;
    // Monkey = 7 
    // Dragon = 3 
    for (int i = 0; i < n ; i++){
        string sent[8];
        for (int x = 0; x <8; x++) cin >> sent[x];
        
        int y = year[sent[7]];
        int s1 = sign[sent[7]]; // sign ref 
        int s2 = id[sent[4]]; // sign new animal
        sign[sent[0]] = s2;
        // cerr << "y: " << y << endl;
        // cerr << "s1: " << s1 << endl;
        // cerr << "s2: " << s2 << endl;
        int delt;
        if (sent[3]=="next"){
            if (s1==s2) {
                 delt = 12;
            } else if (s1>s2){
                 delt = s2 + (12-s1)%12;
            } else{
                 delt = s2 - s1;
            }
            year[sent[0]] = y + delt;
        } else{ // previous 
            if (s1==s2) {
                 delt = 12;
            } else if (s1>s2){
                 delt = s1 - s2;
            } else{
                 delt = s1 + (12-s2)%12;
            }
            year[sent[0]] = y - delt;
        }
        // sign[sent[0]] = s2;
        // cerr << sent[0] << " >> " << year[sent[0]] << endl << endl;
    }
    cout << abs(year["Elsie"]) << endl;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);


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