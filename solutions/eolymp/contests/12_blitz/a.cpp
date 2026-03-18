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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;






void solveB(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    vpi b;
    int sz = 0;
    int curr = -1;
    for (int i = 0; i <n; i++){
        if (a[i] != curr){
            if (curr != -1){
                b.pb({sz,curr});
            }
            sz = 1;
        } else{
            sz++;
        }
        curr = a[i];
    }
    b.pb({sz,curr});
    debug(b);
    int res = 0;
    for (int i = 1; i + 1 < b.size(); i++){
        if (b[i-1].S == b[i+1].S) res = max(res, b[i-1].F + b[i].F + b[i+1].F);
    }
    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < b.size(); i ++ ){
        if (b[i].F > t1){
            t2 = t1;
            t1 = b[i].F;
        } else if (b[i].F == t1){
            t2 = t1;
        } else if (b[i].F > t2){
            t2 = b[i].F;
        }
    }
    debug(t1,t2);
    res = max(res, t1+t2);
    cout << n - res << endl;


    // stack<pi> st;
    // for (int i = 0; i < b.size(); i++){
    //     if (!st.empty()){
    //         if (st.top().F == b[i].F) {
    //             while(!st.empty() && st.top().F == b[i].F){
    //                 st.pop();
    //             }
    //             continue;
    //         }
    //     }
    //     st.push(b[i]);
    // }
    // ll res = 0;
    // while(!st.empty()){
    //     res += st.top().S;
    //     st.pop();
    // }
    // cout << res << endl;
}



int main(){
    int t = 1;
    cin >> t;
    while(t--) solveB();
    return 0;
}
