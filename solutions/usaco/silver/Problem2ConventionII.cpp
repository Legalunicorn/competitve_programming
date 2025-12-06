/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>
#include <queue>

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



void solve(){
    // this is just a simultion 
    // it is literally a priority queue 
    // 1. store priority in separate list 
    // 2. sort the cows by arrival 
    // 3. push all min starting points to PQ 
    // 4. iterate: pop from PQ (highest senority)
    // keep track of time as well 
    // maybe an additional poi dynmiaically shift the start time 
    // every cow before the new start time joins the pq 
    // so we have a J pointer 
    // I got stuck badly on implementation even though the idea was simple 
    // the issue i had was too many moving parts ? my logic was very similar to the editorial 
    // i used a for loop which forced increment, 
    // the answe used a while loop that only increment cur if its used 
    // otherwise we consume the pq first 
    int n; cin >> n;
    vvl a(n);
    ll mn = INF;
    for (ll i=0; i<n; i++){
        ll ai,t;
        cin >> ai >> t;
        mn = min(mn,ai);
        a[i] = {i,ai,t};
    }
    sort(all(a),[](const auto& p, const auto& q){
            return p[1] < q[1];
            });
    auto cmp = [](const auto& p, const auto &q){
        return p[0]> q[0];
    };
    priority_queue<vl,vvl,decltype(cmp)> pq(cmp);
    
    ll time = 0, cur = 0, res = 0;
    while(cur < n || !pq.empty()){
        if (cur < n && a[cur][1] <= time){
            pq.push(a[cur]);
            cur++;
        } else if (pq.empty()){
            time = a[cur][1] + a[cur][2]; 
            cur ++;
        } else{
            vl top = pq.top(); pq.pop();
            res = max(res, time - top[1]);
            time += top[2];
        }
    }
    cout << res << endl;



    // int id =0;
    // vb added(n,false);
    // // for (int i=0;i<n;i++){
    // //     if (a[i][1] == mn){
    // //         pq.push(a[i]);
    // //         added[i] = true;
    // //         id ++;
    // //     }
    // // }
    // // debugm(a);
    // ll res = 0, time = mn;
    // // cerr << mn << endl; 
    // for (int i=0; i<n; i++){
    //     time = max(a[i][1], time);
    //     cerr << time << endl;
    //
    //     // now we set the scence that time has skipped until this cows arival 
    //     if (!added[i]){
    //         added[i] = true;
    //         pq.push(a[i]);
    //     }
    //     // pq cant be empty right ? 
    //     while (!pq.empty()){ // consume the next cow NOW 
    //         vl t = pq.top();
    //         pq.pop();
    //         res = max(res,  time - t[1]);
    //         time +=t[2]; // time to eat 
    //         debugv(t);
    //         cerr << "res?: " << res << " " << time << endl;
    //         // everyone who arrives before time has to join the queue 
    //         while (id<n && a[id][1]<=time && !added[id]){
    //             added[id] = true;
    //             pq.push(a[id]);
    //             id ++;
    //         }
    //     }
    //
    //
    // }
    // // while(!pq.empty()){
    // //     debugv(pq.top());
    // //     cerr << time << endl;
    // //     vl t= pq.top();
    // //     pq.pop();
    // //     res = max(res,time - t[1]);
    // //     time += t[2];
    // // }
    // cout << res << endl; 


    
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
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
