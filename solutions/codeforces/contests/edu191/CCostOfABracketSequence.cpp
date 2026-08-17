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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// sum of N over all T <= 5000 
// n^2 is still passable 
// 25 000 000 
// n^2 fits dp nicely but im not sure 
//
// k <= n 
// n * k 
// problem 
// let dp[n][k] be the MIN COST of the subsequence of S[n..] with K operatinos remaining ly 
// S[N] = 0 because there are no characters left 
//
// but sth is wrong with the transition its not enough to know the min cost of the subp[roblem 
// NOTE: cost is always even 
//
// what about bnary search over min COST? 
// n^2 log n might be too slow though 
//
// given cost = 10 
//
//
// NOTE: this might be greedy as well 
// can we always just remove the 

// NOTE: a subsequence is take from the entire string 
// say i have multiple "()" pairs, remove a set of "()" does not matter which one i choose 
// the only real option is when i remove "(" or ")" individually 
// so we remove all pairs first, or as much pairs as possible 
// then afte4weards "))))))((((" if we have no pairds left itos that pattern, any anytrhing we remove does not matter 
// otherwise we hairs 1. pairs left 2. maybe some excess , and k = 1 
// in this case what do we remove? the matter is like 
// and so it should be remove op timally such that "(" 
// ANTI PATTERN: " ) ))))) (((((((" 
// sparse pairs: insetr anywhere 
// if k = 1, i want to disturb a pair * 
// and it only make sense if the pair i distance has no opposite edges 
// LEFT -> no other right from its right pairs 
// RIGT -> no other left on its left pairs 
//
// idea: we go through all the remainig pairs and we want to check : for the right side, how many right left> 
// for the left side how many right to the left etc.. this is 
//
//
//


// new idea 
// remove the first x OPEN,  and the last k - x CLOSE 
// iterate x over k 
// for each calcualte the score

void solve(){
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    int best = n*10; 
    int resx = 0; // best value for x 
    vi left,right;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') left.pb(i);
        else right.pb(i);
    }
    reverse(all(right));
    debug(s);
    debug(left,right);

    for (int x = 0; x <= k; x++){
        int y = k - x;
        // remove the first x left, 
        // remove the last y right 
        vi temp(n,0);
        for (int i = 0; i < x && i < left.size(); i++) temp[left[i]] = 1;
        for (int i = 0; i < y && i < right.size();i++) temp[right[i]] = 1;
        debug(x,y,temp);
        int cnt = 0; 
        int open = 0;
        for (int i = 0; i < n; i++){
            if (temp[i]==1) continue;
            if (s[i] == '(') open++;
            else{
                if (open > 0){
                    cnt ++;
                    open--;
                }
            }
        }
        if (cnt < best){
            best = cnt;
            resx = x;
        }
        debug(x, cnt);
    }
    debug(resx, best);
    // cerr << endl;

    // time to construct 
    vi res(n,0);
    int resy = k -resx;
    for (int i = 0; i < resx && i < left.size(); i++) res[left[i]] = 1;
    for (int i = 0; i < resy && i < right.size(); i++) res[right[i]] = 1;
    for (auto& r: res) cout << r;
    cout << endl;

    



}
void oldSolve(){

    int n,k;
    cin >> n >> k;
    string s; 
    cin >> s;
    vi res(n,0); // all on 
    vi p(n, -1);
    map<int,vi> mp;
    int id = 0; // ID of each pair 
    stack<int> st;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') st.push(i);
        else{
            if (!st.empty()){
                int l = st.top(); st.pop();
                p[l] = id;
                p[i] = id;
                mp[id].pb(l);
                mp[id].pb(i);
                id++;
            }
        }
    }
    debug(p);
    int take = 0;
    for (int x = 0; x < id; x++){
        if (k <2) break;
        res[  mp[x][0]] = 1;
        res[  mp[x][1]] = 1;
        // reset p 
        p[mp[x][0]] = -1;
        p[mp[x][1]] = -1;
        k -= 2;
        take++;
    }
    debug(p);
    debug(res);
    debug(mp, take,id);
    // cerr << endl;
    if (take == id || k == 0){
        // print asn;
        for (auto& z: res) cout << z;
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++){
        bool valid = true;
        if (p[i] != -1) {
            int pos = p[i];
            int l = mp[pos][0];
            int r = mp[pos][1];
            debug(l,r);
            // check from 0 to l-1 , and r+1 to n-1 
            bool good = true;
            for (int j = 0; j < l; j++){
                if (s[j] == '(' && res[j]==0){
                    good = false;
                    break;
                }
            }
            if (good){
                res[l] = 1; 
                break;
            }
            good = true;
            for (int j = r+1; j < n; j++){
                if (s[j] == ')' && res[j]==0){
                    good = false;
                    break;
                }
            }
            if (good){
                res[r] = 1;
                break;
            }
        }
    }
    for (auto& z:res) cout << z;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
