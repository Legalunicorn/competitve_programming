
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

// NOTE: maybe we need to work from the back 
// i , i + 1 == 
// we also need the min operations 
// 0 -> 1 can be changed freely 
// 1 -> 0 (in pairs)
//
// 1 1 -> 0 0 -> 0 1  
// still possible
// 0 1 
//
// 1 1 
// 0 1

// the impossible case is 
// last char 
// 1 
// 0 
// no but the previous can change 
// i think its always possible as long as its size  >= 2 
// the proof is that we cvan convert the whole strong to "000" then change any to 1 as we nned

// trick case 
// 1 0
// 0 1 
// 


class Solution {
public:
    int minOperations(string s1, string s2) {
        if (s1 == s2) return 0;
        int n = s1.size();
        if (n == 1){
            if (s1[0] == '1' && s2[0] =='0') return -1; // impossible case;
            return 1; // 0, 1 
        }
        int res = n * 10;
        {
            // front 
            int cnt = 0;
            string p = s1;
            string q = s2;
            for (int i = n - 1; i >= 0; i--){
                if (p[i] == q[i]) continue;
                if (p[i] == '0'){
                    p[i] = '1';
                    cnt++;
                } else{
                    // 1 -> 0
                    if (i + 1 < n){
                        if (p[i+1] == '0') {
                            p[i+1] = '1';
                            cnt++;
                        }
                        p[i] = p[i+1] = '0';
                        cnt++;
                        if (q[i+1] == '1'){
                            p[i+1] = '1';
                            cnt++;
                        }
                    } else{
                        // have to look backwards
                        if (p[i-1]=='0'){
                            p[i-1] = '1';
                            cnt++;
                        }
                        p[i] = p[i-1] = '0';
                        cnt++;
                        if (q[i-1]=='1'){
                            p[i-1] = '1';
                            cnt++;
                        }
                    }
                }
            }
            cerr << cnt << endl;
            res = min(res, cnt);
        }
        {
            int cnt = 0;
            string p = s1;
            string q = s2;
            for (int i = 0; i < n; i++){
                if (p[i] == q[i]) continue;
                if (p[i] == '0'){
                    p[i] = '1';
                    cnt++;
                } else{
                    // 1 -> 0
                    if (i -1 >= 0){
                        if (p[i-1]=='0'){
                            p[i-1] = '1';
                            cnt++;
                        }
                        p[i] = p[i-1] = '0';
                        cnt++;
                        if (q[i-1]=='1'){
                            p[i-1] = '1';
                            cnt++;
                        }
                    } else{
                        if (p[i+1] == '0') {
                            p[i+1] = '1';
                            cnt++;
                        }
                        p[i] = p[i+1] = '0';
                        cnt++;
                        if (q[i+1] == '1'){
                            p[i+1] = '1';
                            cnt++;
                        }
                    }
                }
            }
            cerr << cnt << endl;
            res = min(res, cnt);
        }
        {
            int cnt = 0;
            string p = s1;
            string q = s2;
            for (int i = 0; i < n; i++){
                if (p[i] == q[i]) continue;
                if (p[i] == '0'){
                    p[i] = '1';
                    cnt++;
                } else{
                    // 1 -> 0
                    if (i + 1 < n){
                        if (p[i+1] == '0') {
                            p[i+1] = '1';
                            cnt++;
                        }
                        p[i] = p[i+1] = '0';
                        cnt++;
                        if (q[i+1] == '1'){
                            p[i+1] = '1';
                            cnt++;
                        }
                    } else{
                        // have to look backwards
                        if (p[i-1]=='0'){
                            p[i-1] = '1';
                            cnt++;
                        }
                        p[i] = p[i-1] = '0';
                        cnt++;
                        if (q[i-1]=='1'){
                            p[i-1] = '1';
                            cnt++;
                        }
                    }
                }
            }
            cerr << cnt << endl;
            res = min(res, cnt);
        }
        {
            int cnt = 0;
            string p = s1;
            string q = s2;
            for (int i = n - 1; i >= 0; i--){
                if (p[i] == q[i]) continue;
                if (p[i] == '0'){
                    p[i] = '1';
                    cnt++;
                } else{
                    // 1 -> 0
                    if (i -1 >= 0){
                        if (p[i-1]=='0'){
                            p[i-1] = '1';
                            cnt++;
                        }
                        p[i] = p[i-1] = '0';
                        cnt++;
                        if (q[i-1]=='1'){
                            p[i-1] = '1';
                            cnt++;
                        }
                    } else{
                        if (p[i+1] == '0') {
                            p[i+1] = '1';
                            cnt++;
                        }
                        p[i] = p[i+1] = '0';
                        cnt++;
                        if (q[i+1] == '1'){
                            p[i+1] = '1';
                            cnt++;
                        }
                    }
                }
            }
            cerr << cnt << endl;
            res = min(res, cnt);

        }
        return res;
        // we can try two methods, fronbt to back, or back to fronit 

    }
};

void solve(){
    
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
©leetcode
