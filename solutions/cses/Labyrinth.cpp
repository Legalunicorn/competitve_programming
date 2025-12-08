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
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}



//Dijsktras with trace trable 

void solve(){
    int n,m;
    cin >> n >> m;
    vvi trace(n,vi(m,-1));
    vector<string> grid(n);
    int sx =0 , sy = 0, ex = 0, ey = 0;
    for (int i=0;i<n;i++){
        string s; cin >> s;
        for (int j=0;j<m;j++){
            if (s[j]=='A'){
                sx = i;
                sy = j;
            }
            if (s[j]=='B'){
                ex = i;
                ey = j;
            }
        }  
        grid[i] = s;
    }

    auto cmp = [&](const auto& a, const auto& b){
        return a[0] > b[0];
    };
    priority_queue<vi,vvi,decltype(cmp)> pq(cmp);

    vvi dist(n,vi(m,INT_MAX));
    dist[sx][sy] = 0;
    pq.push({0,sx,sy});
    while(!pq.empty()){
        vi top = pq.top(); pq.pop();
        int w = top[0], x = top[1], y = top[2];
        if (x==ex && y==ey){
            break;
        }
        for (int i=0;i<4;i++){
            vi d = dirs[i];
            int r = x+d[0];
            int c = y+d[1];
            if (r>=0 && r<n && c>=0 && c<m && grid[r][c]!='#'){
                if (w+1<dist[r][c]){
                    trace[r][c] = i;
                    dist[r][c] = w+1;
                    pq.push({w+1,r,c});
                }
            }
        }
    }
    if (dist[ex][ey]==INT_MAX){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << dist[ex][ey] << endl;
    string res; 
    while(trace[ex][ey]!=-1){
        int v = trace[ex][ey];
        if (v==0){
            res += 'U';
            ex++;
        } else if (v==1){
            res +='D';
            ex--;
        } else if (v==2){
            res +='L';
            ey++;
        } else if (v==3){
            res +='R';
            ey--;
        }
    }
    reverse(all(res));
    cout << res << endl;

};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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