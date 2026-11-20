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

struct node{
    int cnt;
    bool isEnd;
    node*   child[26];
    node(){
        cnt = 0;
        for (int i = 0; i < 26;i++) child[i] = nullptr;
    }
};

struct trie{
    node* root;
    trie(){
        root = new node();
    }
    void insert(string word){
        node* cur = root;
        for (char c: word){
            int idx = c- 'a';
            if (!cur->child[idx]){
                cur->child[idx] = new node();
            }
            cur->cnt++;
            cur = cur -> child[idx];
        }
        cur->cnt++;
        // cur->isEnd = true;
    }

    int query(string word){
        node* cur = root;
        for (char c: word){
            int idx = c-'a';
            if (!cur->child[idx]) return 0;
            cur = cur->child[idx];
        }
        // return cj
        debug(word, cur->cnt, cur->isEnd);
        return cur->cnt;
        // return cur->cnt - (cur->isEnd);
    }
};


void solve(){
    int n;
    cin >> n;
    trie t;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        debug(s);
        t.insert(s);
    }

    int m; cin >> m;
    for (int i = 0;i < m; i++){
        string s; cin >> s;
        debug(s);
        cout << t.query(s) << endl;
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
    while(T--) solve();
    return 0;
}
