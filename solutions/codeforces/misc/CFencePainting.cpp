/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>
#include <iterator>

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

// this problem is alot more annoying then it appears to be ! 
// lets restart from it 
// our initial approach is just positon spam 
// but it fails to account that the PAINTERS arrive in order 
// what we should do instead is process the painters one by one 
//
//
// instead of maintaing counts, we maintain demands ? 
// for each painter there must be a demand for him, 
// if there isnt, he needs to paint a color that someone else will cover for him 
// but he shouldnt force someone else who has other commitments 
// he needs to force someone who is in EXCESS 
// so we should have an pool of excess painters, what do we do with them? 
// we know the color + position of said excess painters 
// we just have to paint any B-cell that wants that target color 
//
// how do we maintain excess? 
// we can use a stack for each color of painters mayber? 
//
// mini summary 
// 1. painters must have a demand to filful 
// 2. if there are demanded somewhere, just fill them in greedily 
// 3. if they are not in demand but their color exist, just paint that color 
// 4. if their color is not in B at all, they should find any painter who is in excess and take it from there 
// 5. there should be no demand after its done, OR A = B check 
//
// how do we maintain 1. demand   2. excess? 
// demands needs to be grouped by color, 
// while excess not really 
// excess will only know based on count comparision 
// excess can just be a stack of color 

int tc = -1;
void solve(){
    tc++;
    // our acess must be met with colors we have to spare ? 
    // can we repaint the same fence?
    // if yes its simpler, the access overflows 
    // otherwise we have to
    int n,m;
    cin >> n >> m;
    vi a(n), b(n), c(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    for (auto& z:c) cin >> z;

    // stack<int> excess;
    set<int> excess2;
    // map<int,int> excess;
    map<int,int> cfreq, bpos;
    map<int, stack<int>> demand;

    for (int i=0;i<n;i++){
        bpos[b[i]] = i;
        if (a[i] != b[i]) demand[b[i]].push(i);
    }
    for (auto& x: c) cfreq[x]++;

    // or should the excess be pushed in some sort of order? 
    for (auto& [color,quant]: demand){
        if (cfreq[color] < quant.size()){
            cerr << tc <<  ":  didnt meet freq: " << endl;
            cout << "NO" << endl;
            return; // we cant do anyhing
        }

    }
    for (auto& [color,cnt]: cfreq){
        // cerr << color << " " << cnt << endl;
        // if (!demand.count(color)) excess2.insert(color);
        if (! bpos.count(color)) continue;
         if (cfreq[color] >= demand[color].size()) excess2.insert(color);
    }
    //
    // for (auto& x: excess2) cerr << x << " ";
    // cerr << endl;
    // cerr << "end excess" << endl;

    vi res(m,-1);
    for (int i=0; i<m ;i++){
        // cerr << i << endl;
        // cerr << "x: " << *excess2.begin() << endl;
        int col = c[i];
        if (demand.count(col) && demand[col].size()>0){
            cerr << "opt1" << endl;
            res[i] = demand[col].top();
            demand[col].pop();
            cfreq[col]--;  //cfreq or bfreq? 
            if (cfreq[col]==0) excess2.erase(col);
            // if (cfreq[col] <= demand[col].size()) excess2.erase(col);

        } else  if (bpos.count(col)){
            cerr << "opt2" << endl;
            res[i] = bpos[col];
        } else{ // no one want it, we have to throw into our excess? 
            // cerr << "opt3" << endl;
            if (excess2.empty()){
                // cerr << "pos: " << i << endl;
                // cerr << "no empty left" << endl;
                cout << "NO" << endl;
                return;
            }
            int col = *excess2.begin();
            if (demand.count(col) && demand[col].size()>0){
                int pos = demand[col].top();
                res[i] = pos;
            } else{
                int pos = bpos[col];
                res[i] = pos;
            }
            // int pos = demand[col].top();
            // res[i] = pos;
            // just paint the index of an 

            // auto top = *excess.begin();


        }
    }
    cout << "YES" << endl;
    for (auto& x: res) cout << x+1 << " ";
    cout << endl;


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
