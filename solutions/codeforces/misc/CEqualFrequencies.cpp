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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi freq(26);
    for (char&c:s){
        freq[c-'a']++;
    }
    sort(rall(freq));
    debug(freq);
    int res = n;
    int best = n;
    for (int i = 1 ; i <= n; i++){
        if (n % i == 0 && n/i <= 26){

            // calculate how much dont need to move
            int g = n/i;
            // i -> size
            int cnt = 0;
            for (int x = 0; x < g; x++) cnt += min(i, freq[x]);
            int evl = n - cnt;
            debug(i,g, evl);
            if (evl < res ){
                res = evl;
                best = i;
            }
        }
    }
    cout << res << endl;
    vpi f(26);
    for (int i = 0; i < 26;i++) f[i].S = i;
    for(char c: s){
        f[c-'a'].F ++;
    }
    sort(rall(f));
    set<int> chosen;
    priority_queue<pi, vpi, greater<pi>> pq;
    map<int,int> mp;
    int how = n/best;
    for (int i = 0; i < how; i++){
        chosen.insert(f[i].S);
        pq.push(f[i]);
        mp[f[i].S] = f[i].F;
    }

    debug(chosen);
    debug(how,best);
    // best -> the frequency
    for (char& c: s){
        if (!chosen.count(c-'a')){
            auto t = pq.top();
            pq.pop();
            c = (char)(t.S + 'a');
            t.F++;
            mp[t.S]++;
            if (t.F < best) pq.push(t);
        } else{
            int x = c-'a';
            if (mp[x] <= best) continue;
            mp[x]--;
            auto t = pq.top();
            debug(c, t);
            pq.pop();
            c = (char)(t.S+'a');
            t.F++;
            mp[t.S]++;
            pq.push(t);
        }
    }
    cout << s << endl;
    
    // hella anoying to implement 
    // 1. all extra from selected must go to others 
    // 2. all not inside the group must go to others
    
    // iterate the string
    // if NOT inside selected
    //  -> find the lowst freq in selected and convert
    // if IS a selected 
    //  -> if more than X   
    //      -> find the lowest freq in selected 
    //  -> if <= X, ignore
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
