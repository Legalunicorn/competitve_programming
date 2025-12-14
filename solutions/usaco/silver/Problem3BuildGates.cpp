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

// very cool idea 
// EXANDING the graph by mapping 1 step into 2 
// Creating a boundaring and limitting inside it (minx, maxx)
// tooks hints from solution but rest is trivial and did on my own

const int MAX_N = 4005;
int grid[MAX_N][MAX_N] = {0};
bool seen[MAX_N][MAX_N] = {false};

void dfs(int r, int c,int a, int b, int e, int d){
    seen[r][c] = true;
    for(const vi& dir:dirs){
        int row = r+dir[0];
        int col = c+dir[1];
        if (row<a || row>b| col<e || col>d || seen[row][col] || grid[row][col]==-1) continue;
        dfs(row,col,a,b,e,d);

    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = MAX_N/2;
    int y = MAX_N/2;
    cerr << s << endl;
    // memset(grid,0,sizeof(grid));
    // memset(seen,false,sizeof(seen));
    int minx = x, maxx = x;
    int miny =y, maxy = y;
    for (char c: s){
        if (c=='N'){
            grid[x][y-1] = -1;
            grid[x][y-2] = -1;
            y-=2;
            miny = min(miny,y);
        } else if (c=='E'){
            grid[x+1][y] = -1;
            grid[x+2][y] = -1;
            x += 2;
            maxx = max(maxx,x);
        } else if (c=='S'){
            grid[x][y+1] = -1;
            grid[x][y+2] = -1;
            y += 2;
            maxy = max(maxy,y);
        } else {
            grid[x-1][y] = -1;
            grid[x-2][y] = -1;
            x -=2;
            minx = min(minx,x);
        }
    }
    minx--; miny--;
    maxx++; maxy++;
    cerr << "ok " << endl;
    // flood fill 
    int res = 0;
    for (int i=minx; i<=maxx; i++){
        for (int j=miny; j<=maxy; j++){
            if (grid[i][j]!=-1 && !seen[i][j]){
                res++;
                dfs(i,j,minx,maxx,miny,maxy);
            }
        }
    }

    cout << res -1 << endl;
};
/*
    its not clear in the question how the partition works 
    if he just makes a squnce is the "area" inside an area or not?? 
    base on the example, the fence are infinitely thin 
    so a square still produces an areas 

    the second issue is that how do we find connected componenets? 
    we might have to "expand" the graphs or something so that the fence takes up data 
    this should work but its hard to implement?
    for example we just 

    AH fuck. why not just used a [5000][5000] array and start in the middle 

    then every action we just double it 

    how do we define a partition? 
    the ansewr is just the number of connected compononets -1 
    since N <= 1000 

    he can move at most 1000 steps 
    the tricky part is that we are on an infinite plane 
    - process the string first, find the min x and min y 
    - then we normalise the plane by min x min y 
    - now every point is possible 
    - create a grid and paint the graph 

*/


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
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
