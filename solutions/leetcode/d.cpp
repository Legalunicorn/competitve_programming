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

// every starting letter of "a" is an equivalence partition 
// hence we can just test for all starting of [i] 
// by has to start at some a[i] if its true 
//
// so im claiming the exact string exist 
// it could be a case of 
// (1) finding if repetition leads to equialence 
// (2) finding the number of repetitio needed
//
// i think we can try to mutate "a" and see if it matches "b" at some point, for up to length "b"
//


class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        bool found = false;
        ll n = a.size();
        ll m = b.size();
        ll alen = n * (ll)x;
        ll blen = m * (ll)y;
        if (blen  > alen) return false;
        debug(a,b,x,y);

        for (int i = 0; i < n; i++){
            ll len_need = blen + i;
            ll aned = len_need/n;
            if (len_need % n != 0) aned++;
            if (aned > x) continue;
            debug(i);

            // construct a mutation of "a" that guarantees cycle "b"
            // this is hella tricky because "a" and "b" alignment can be funny af
            // but if we just "guess" the cycle isnt that long 
            // actually by PHP it should be sub 100^2
            // the cases are funny, its possible to find the loop, we alrady found the entire "by"
            int cur = i;
            int b_id = 0;
            vb used(n);
            int inspec = 0;
            bool valid = true;
            while(valid){
                // every character in b
                if (used[cur]) return true; // valid!
                used[cur] = true;
                for (int j = 0; j < m; j++){
                    if (a[cur] == b[j]){
                        cur = (cur+1)%n; // advance
                        inspec++;
                    } else{
                        valid = false;
                        debug(i, inspec, a[cur], b[j]);
                        break; // we're done
                    }
                    // we match anyways return true
                    if (inspec == blen) return true;
                }
            }
        }
        return false;
        // return found;
    }
};

