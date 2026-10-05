#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE: 
// we have to process by distance
//  0 -> this is a treasure point 
//  island IN  A LINE -> the distance must be linear 
//  the values of "-1" are fixed are they? 
// BFS from all the "0s" and SEEN 
// the arr must be a MIN 
// if d[v] < d[u] // impossible, unless -1 was triggered for that d[v]? 
//
//
// NOTE: we only need ANY possible set 
// we should inspect the "-1" elements 
// IF they are an island 
// -> the neighbours are either an Island "0" , or "1" or "-1" 
//
// NOTE: 
// bfs and ignore -1 
// if d[v] == 1+d[u], its expected 
// if d[v] > 1+d[u], its impossible 
// if d[v] = d[u] -1 
// if d[v] < d[u] -1, impossible
//  -> only possible if v += d[v] has an unknown island?.. = -1 
//  -> if we assign like this though we hav a whole portion skipped as part of the dfs 
//  -> its poi
//
//
//  interesting obs, -> if we had a graph, it must be acyclic
//  dfs might be overkill 
//
//  why not we analyize SEGMENTS of -1 
//  x x [-1, -1 ... -1] x x 
//  if the whole arry is -1 trivial.. 
//  if the "sides" of the (-1) chain is > 0, we can constrict the "-1" conses 
//  until we get 
//  0 , -1 -1 -1 -1 , 0 -1 , 0 0  -1 , 0 0 ,0 
//  but by then we can just set all the -1 to treausre and it should be trivial
// what if -1 chain is atached to the sides of the array? 
// we can just ignore the attached side


//   NOTE: 
//   1. abs(a[i] - a[i+-1]) == 1 is necessary
//
//   try to think invariants? 
//   -> try to focus on LARGE numbers ? because the
//   if "x" thjen x-1, x-2,... must exist in ONE direction
//   -> o(n) we visit each position at most 
//
//   seems wrong also 
//
//   if its crazy we mighjt need to do DP 
//
// the initial dfs might be correct 
// -> the very special case is d[v] == d[u]-1, in which 

void solve(){
    int n;
    cin >> n;   
    vi a(n);
    for (auto& z:a)cin >>z;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1){
            found = true;
            break;
        }
    }
    if (!found){
        for (int i  = 0; i < n; i++) cout << 1;
        cout << endl;
        return;
    }

    int i = 0;
    int last = -2; // inv 
    while(i<n){
        if (a[i] != -1) {
            last = a[i];
            i++;
        } else{
            int j = i;
            while(j+1<n && a[j+1] == -1) j++;
            int dist = j - i + 1;
            if (last == -2) { // guaranteed the j is not n also PREFIX cxase
                int right = a[j+1];
                int cnt = 1;
                bool up = true;
                if (j -i + 1 >= right) up = false;
                for (int st = j; st >= i; st--){
                    if (!up) a[st] = max(0,right-cnt);
                    else a[st] = right+cnt;
                    cnt++;
                }
                last = right;
                i = j+1;
            } else{
                if (j == n-1){ // tailing -1,..  SUFFIX CASE
                    int t = last;
                    int cnt =1;
                    bool up = true;
                    if (j-i+1 >= t) up = false;
                    for (int st = i; st <= j; st++){
                        if (!up) a[st] = max(0, t-cnt);
                        else a[st] = t+cnt;
                        cnt++;
                    }
                    break;
                    // last 
                    // i = j+1;
                } else{ // VALID RANGE CASE
                    int left = last;
                    int right = a[j+1];
                    // there must be a min distance too actually 
                    if (abs(right-left)>dist+1){
                        // impossuible! 
                        cout << -1 << endl;
                        return;
                    }
                    if (left + dist + 1 == right) { // increasing
                        int cnt = 1;
                        for (int z = i; z <= j; z++){
                            a[z] = left + cnt;
                            cnt++;
                        }
                        i = j+1;
                        last = a[j+1];
                        continue;
                    } else if (right + dist + 1 == left) { // decreaseing
                        int cnt = 1;
                        for (int z = j; z >= i; z--){
                            a[z] = right + cnt;
                            cnt++;
                        }
                        i = j +1;
                        last = a[j];
                        continue;
                    } else {
                        int need = left + right - 1;
                        if (dist< need) {
                            int len = dist + 1;

                            for (int k = 1; k <= dist; ++k) {
                                a[i+k-1] = min(left+k, right+len-k);
                            }
                            i = j+1;
                            last = a[j+1];
                            continue;
                        }
                        int start = i;
                        for (int z = left-1; z >= 0; z--){
                            a[start] = z;
                            start++;
                        }
                        int end =j ;
                        for (int z = right-1; z >= 0; z--){
                            a[end] = z;
                            end--;
                        }
                        for (int z = i-1+left; z <= j+1-right; z++){
                            a[z] = 0; // set as island
                        }
                        i = j + 1;
                        last = a[j];
                        continue;
                    }
                }
            }
        }
    }
    // do a dfs
    vb seen(n, false);
    queue<int> q;
    debug(a);
    for (int i = 0; i < n; i++){
        if (a[i] == 0)  {
            // debug("pussh", i);
            q.push(i);
            seen[i] = true;
        };
    }
    if (q.empty()){
        cout << -1 << endl;
        return;
    }
    int nx = 1;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int t = q.front();
            // debug(t, a[t], nx, seen);
            q.pop();
            if (t-1>=0 && !seen[t-1]){
                if (a[t-1] != nx){
                    cout << -1 << endl;
                    return;
                } else{
                    seen[t-1] = true;
                    q.push(t-1);
                }
            }
            if (t+1<n && !seen[t+1]){
                // debug(t+1, a[t+1], nx);
                if (a[t+1] != nx){
                    cout << -1 << endl;
                    return;
                } else{
                    seen[t+1] = true;
                    q.push(t+1);
                }
            }
        }
        nx++;
    }

    for (int i = 0; i < n;i++){
        if (a[i] == 0) cout << 1;
        else cout << 0;
    }
    cout << endl;

    // clean up -> try to bfs

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
