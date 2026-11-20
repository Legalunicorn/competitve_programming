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
// we can target the position that is off 
// or we can greedy? but the alignedment is not sure 
//
// find the longest common prefix/suffic?
// or basically, the first pair that differens, what does it say? 
// we have to move from "A" or "B" it doesnt matter
// lets say we move from "A"
// then we have to skip "A"
// so we stash a[i], a[i]!=b[i]
// then when then is a secon dmismatch 
//
// there is two types, a forward shift or a backward shift 
// i think we can just assume forward
// then assume bacwards, as long as one works 
//
// forward 

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    bool found = false;
    int d = -1;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){ 
            d = i;
            break;
        }
    }
    debug(a);
    debug(b);
    debug(d);
    if (d == -1 || a==b) { // must be performce
        cout << "Yes" << endl;
        return;
    }
    if (d == n-1){
        cout << "No" << endl;
        return;
    }
    {
        int stash = b[d];
        int pa = d;
        int pb = d+1;
        bool used = false;
        bool valid = true;
        while(pa < n && pb < n){
            debug(stash,pa,pb);
            if (a[pa] != b[pb]){
                if (used) {
                    valid = false;
                    break;
                }
                if (a[pa] == stash){
                    used = true;
                    pa++;
                    continue;
                } else{
                    valid = false;
                    break;
                }
            }
            pa++;
            pb++;
        }
        if (valid){
            // we found and remedied
            if (pa == n && pb == n){
                cout << "Yes" << endl;
                return;
            }
            // it was the last case
            if (pb == n && pa == n-1 && a[n-1] == stash){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    swap(a,b);
     {
        int stash = b[d];
        int pa = d;
        int pb = d+1;
        bool used = false;
        bool valid = true;
        while(pa < n && pb < n){
            debug(stash,pa,pb);
            if (a[pa] != b[pb]){
                if (used) {
                    valid = false;
                    break;
                }
                if (a[pa] == stash){
                    used = true;
                    pa++;
                    continue;
                } else{
                    valid = false; 
                    break;
                }
            }
            pa++;
            pb++;
        }
        if (valid){
            // we found and remedied
            if (pa == n && pb == n){
                cout << "Yes" << endl;
                return;
            }
            // it was the last case
            if (pb == n && pa == n-1 && a[n-1] == stash){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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
