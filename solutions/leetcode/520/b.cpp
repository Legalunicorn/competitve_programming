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

//#define endl '\n' 
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






class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& a) {
        int n = a.size();
        //diff array nad coord compress? 
        // but that not the number of intersectiung
        // we can repet same logic but coimpress maybe?> 
        // for a given interval, NON intersection is 
        // end before S , or start after E 
        // are these mutually exclusivea? yes 
        // so we can do union as addition 
        // count 1. how many start before S 
        // 2. how many end after E 
        ll res = 0;
        sort(all(a));
        debug(a);
        vi b(n), c(n);
        for (int i = 0; i < n; i++) b[i] = a[i][1];
        sort(all(b));
        for (int i = 0; i < n; i++) c[i] = a[i][0];
        cerr << 123123 << endl;
        debug(b);
        debug(c);
        for (int i = 0; i < n; i++){
            // count END bef  
            ll cnt = 0;
            debug(i, a[i]);
            {
                int l = 0, r = n-1, evl = -1;
                while(l<=r){
                    int m = (l+r)/2;
                    // END befor emy start  
                    if (b[m] < a[i][0]){
                        evl = m;
                        l = m + 1;
                    } else r = m -1;
                }
                debug(evl);
                if (evl !=-1) cnt+=(evl+1);
            }
            {
                int l = 0, r = n-1, evl = -1;
                while(l<=r){
                    int m = (l+r)/2;
                    // start (c) AFTER a[i][1]
                    if (c[m] > a[i][1]){
                        evl = m;
                        r = m -1;
                    } else l = m +1;
                }
                debug(evl);
                if (evl!=-1) cnt += (n - evl);
                // if (evl!=-1) cnt+=(gccevl+1);
            }
            ll tot = n - cnt -1;
            debug(cnt, tot);
            // cerr << endl;
            res+=tot;
        }

        return res/2;
    }
};



// int x(){
//     int n;
//     cin >> n;
//     vvi b(n, vi(2));
//     for (int i = 0; i < n; i++){
//         int l,r;
//         cin >> b[i][0] >> b[i][1];
//     }
//     Solution sol;
//     cout << sol.countIntersectingIntervals(b) << endl;
//
// };

//



