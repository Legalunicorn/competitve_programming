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

// after each operation we need to print the rizziness 
// we can try offline queries ? 
// we need to combinute the score after EACH query 
// naively its O(N) per query , N is the current size 
// maybe we can do some math manipulation 
// can we maintain the score separate from the elements in the array? 
// i came up with some weird system for this but its not really data structures 
// the idea is that we maintain both reverse and forward 
//

void solve(){
    int q;
    cin >> q;
    ll f_curr = 0, f_prev = 0, b_curr = 0, b_prev = 0;
    ll sum = 0;
    deque<ll> nums;
    
    bool front = true;

    auto s1 = [&]() -> void{
        debug(nums.front(), nums.back());
        if (front){
            int bk = nums.back();
            nums.pop_back();
            nums.push_front(bk);
            debug("AIOJSJOIAJSOAIJSOIA ", nums.front(), nums.back());
            f_curr = f_prev + sum;
            f_prev = f_curr - nums.size()*nums.back();
            b_curr = b_prev + nums.size()*nums.front();
            b_prev = b_curr - sum;
        } else{
            int bk = nums.front(); nums.pop_front();
            nums.push_back(bk);
            debug("AHHHHHHHHHHHHH",nums.front(), nums.back());
            f_curr = f_prev + sum;
            f_prev = f_curr - nums.size()*nums.front();
            b_curr = b_prev + nums.size()*nums.back();
            b_prev = b_curr - sum;
            cerr << "END OP";
            debug(b_curr,b_prev);

        }
    };

    auto s2 = [&]() -> void{
        // front = !front;
        swap(f_curr,b_curr);
        if (front){
            f_prev = f_curr - nums.size()*nums.front();
            b_prev = b_curr - sum;
        } else{
            f_prev = f_curr - nums.size()*nums.back();
            b_prev = b_curr - sum;
        }
        front = !front;
    };
    
    auto s3 = [&](ll val) -> void{
        sum += val;
        if (front) nums.push_back(val);
        else nums.push_front(val);

        f_prev = f_curr;
        f_curr = f_curr + nums.size()*val;
        b_prev = b_curr;
        b_curr = b_curr + sum;
    };

    int tc = 0;
    while(q--){
        tc++;
        int s; cin >> s;
        if (s==1){
            s1();
        } else if (s==2){
            s2();
        } else{
            ll v; cin >> v;
            s3(v);
        }
        debug(tc, s, front);
        debug(f_curr, f_prev);
        debug(b_curr, b_prev);
        debug(nums);
        cerr << endl;
        cout << f_curr << endl;
    }




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
