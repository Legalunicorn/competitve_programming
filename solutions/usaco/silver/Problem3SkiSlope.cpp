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

// I think i have quite a complicated solution 
// 1. construct a tree using the input (reverse the edges of slop)
// 2. do a dfs and maintain a PQ of max size 10 
// 3. associate each NODE to the SUM enjoyment and top 10 values 
// 4. sort the nodes based on difficulty, using custom comparator 
// 5. do a prefix MAX of the sorted difficulty 
// 6. for each friend, binary search for diff[node][c] <= skill
// 7. return the max prefix sum
//
//
//
// I had the exact same idea as the editorial but failed to implement! 
// Definitely overthinking it 

void solve(){
    int MAXC = 11;
    int n;
    cin >> n;
    vl path_enjoy(n), enjoy(n), diff(n), max_vas(n); 
    diff[0] = 0;
    enjoy[0] = 0;
    path_enjoy[0] = 0;
    vector<pair<int,vl>> mp(n);
    for (int i = 0; i < n; i++) {
        mp[i].F = i;
        mp[i].S.assign(11,0);
    }
    vvi g(n);
    for (int i=1;i<n;i++){
        int end;
        ll d, e;
        cin >> end >> d >> e;
        end--;
        g[end].pb(i);
        enjoy[i] = e;
        diff[i] = d;
    }

    // multiset<ll> ms;
    // for (int i=0;i<11;i++) ms.insert(0);
    auto dfs = [&](auto& dfs, int u, int p, ll tot_enjoy) -> void{
        path_enjoy[u] = tot_enjoy;
        if(p != -1){
            mp[u].S = mp[p].S;
            mp[u].S.pb(diff[u]);

        }

        for (int v : g[u]){
            if (v==p) continue;
            dfs(dfs, v, u, tot_enjoy + enjoy[v]);
        }
        // for (int i=0;i<11;i++){


    };

    dfs(dfs,0,-1,0LL);
     for (int i=0;i<n;i++){
        sort(mp[i].S.rbegin(),mp[i].S.rend());
        mp[i].S.resize(11);
        reverse(all(mp[i].S));
        // for (int j=0; j< 11; j++){
        //     cerr << mp[i].S[j] << " ";
        // }
        // cerr << endl;
    }   

    sort(all(mp),[&](const auto& p, const auto& q){
        const vl&  pp = p.S, qq = q.S;
        for (int i=0;i<11;i++){
            if(pp[i] < qq[i]) return true;
            else if (pp[i] > qq[i]) return false;
        }
        return path_enjoy[p.F] > path_enjoy[q.F];
    });
    

    ll mx = path_enjoy[ mp[0].F ];
    for (int i=0; i<n; i++){
        mx = max(mx, path_enjoy[mp[i].F]);
        max_vas[i] = mx;
        // for (int j=0; j< 11; j++){
        //     cerr << mp[i].S[j] << " ";
        // }
        // cerr << endl;
    }

    auto bs = [&](ll lim, int pos){
        int l = 0, r = n-1;
        int res = -1;
        while(l<=r){
            int m = (l+r)/2;
            if (mp[m].S[pos] <= lim){
                res = m;
                l = m +1;
            } else r = m -1;
        }
        return res;
    };
    int m; cin >> m; 
    for (int i = 0; i<m ;i++){
        ll s,c;
        cin >> s >> c;
        int pos = 10 - c;
        int ans = bs(s,pos);
        if (ans==-1) cout << 0 << endl;
        else cout << max_vas[ans] << endl;

    }

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
