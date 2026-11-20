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


/// all type "t"
// and all "same color"

// this is some bullshit question 
// it could be greedy and if so its a stack

// each type has only ONE group size
// so each element cano only be rmoved one wa

class Solution {
public:
    bool canRemoveAll(vector<int>& type, vector<int>& col, vector<int>& g) {
        bool res = true;
        int n = type.size();
        int m = g.size();
        map<int,int> mp; 
        stack<vi> st;
        for (int i = 0; i < n;i++){
            int t = type[i], c = col[i];
            if (st.empty()){
                st.push({t,c,1});
            } else{
                auto& u = st.top();
                if (u[0]== t && u[1] == c) {
                    u[2]++;
                } else {
                    st.push({t,c,1});
                }
            }
            // clear the stack
            bool del = true;
            while(st.size() > 0 && del){
                del = false;
                auto& u  = st.top();
                int t = u[0], c = u[1], f = u[2];
                int rem = g[t];
                f %= rem;
                if (f== 0){
                    del = true; // remove it 
                    st.pop(); // remove the top
                } else{
                    u[2] = f; // update the freq
                } 
                
            }
        }
        return st.size() == 0;
    }
};
