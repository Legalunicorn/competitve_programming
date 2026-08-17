#include <bits/stdc++.h>
#include <deque>
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
    node* next;
    node* back;
    // string val;
    deque<char> val;
    node(){
        next = nullptr;
        back = nullptr;
    }
};


void solve(){
    string s;
    // cin >> s;
    // cin.ignore();
    getline(cin, s);
    debug(s);
    node root;
    node* front = &root;
    node* back = &root;
    node* cur = &root;
    int len = 0;
    for (char c: s){
        if (c=='<'){
            while(cur->val.size() == 0){
                if (cur->back==nullptr) break;
                cur = cur->back;
            }
            if (cur->val.size()>0) cur->val.pop_back();
        } else if (c=='['){
            node* newfront = new node();
            cur = newfront;
            newfront->next = front;
            front->back = newfront;
            front = newfront;
        } else if (c ==']'){
            cur = back;
        } else{
            cur->val.pb(c);
        }
    }
    string res;
    cur = front;
    while(cur != nullptr){
        for (char c: cur->val){
            res+=c;
        }
        cur = cur->next;
    }
    cout << res << endl;
    


    // NOTE: i have disgusting linked list solution 
    //
    // debug(s);
    // string res ="";
    // deque<char> dq;
    // bool back = true;
    // for (char c: s){
    //     if (c=='<') {
    //         if (back && dq.size() >0 ) dq.pop_back();
    //         continue;
    //     }
    //     else if (c == ']') back = true;
    //     else if (c =='[') back = false;
    //     else{
    //         if (back) dq.push_back(c);
    //         else dq.push_front(c);
    //     }
    //     debug(dq, back);
    // }
    // for (char c: dq){
    //     debug(c);
    //     res += (c);
    //     // res+= to_string(c);
    // }
    // cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    cin.ignore();
    while(T--) solve();
    return 0;
}
