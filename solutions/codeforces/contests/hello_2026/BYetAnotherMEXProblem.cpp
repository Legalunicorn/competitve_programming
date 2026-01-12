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

// is this an observation question ? 
// 1. we have mutliple options but we must only remove one 
// say its like 0 0 1 2 
// and the othe 0 1 2 2 
// can we fix something? 
// how do we find the mex in the first place? 
// given n and k, we need to remove n - k + 1 elements 
// we can deleted ANY number from the window 
// we can select ANY range with the MEX 
// k = 4, [0, 1, 2 ,3 ]
// IF 0 is missing, the answer will be 0 no matter what we do 
// must guarentee 0 is present. 
// then we should also never remove a 0
// question is what do we remove 
// i think the answer is just MEX of some answer 
// n = 7, k = 5 
// remainzing side = 4 
// claculare REM, remaining size 
// 1. sort the array 
// 2. get the best REM, 
// 3. you can remove any 
//
//
// you can remove ANY number from the best(s) MEX interval 
// 1. if a number is repreated, remove it 
// 2. if the MEX = k (perfect MEX), then we must remove which every number is repeated else where? otherwise 
// we remove the largest element? 
// 1. map<int,int> freq;
//
// 

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> freq;
    for (auto& x:a) freq[x]++;

    int left = n - k + 1; // how have numbe we have to delete 
    int res = k-1; // the best possible answer 
    for (int i=0;i<k;i++){
        if (!freq.count(i)){
            res = min(res,i);
            break;
        } else{
            int cnt = freq[i];
            int low = min(cnt-1,left);
            left -= low;
            // if (left==0) break;
        }
    }
    cout << res << endl; 
    // we will be left with a size of k - 1 
    // in that case, what if we re


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
