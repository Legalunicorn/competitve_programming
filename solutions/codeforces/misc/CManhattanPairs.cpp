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


// PERF: Notes, Ideas
// all points must be selected anyways
// we can try exchange argument
//
// manhan = dx + dy 
// we can split by one direction 
// naive algo is 
// 1. sort by x 
// 2. joint the edges
//  1 (d1) 2 (d2) 3 (d3) 4 
//
//  (1,2) (3,4)  -> d1 + d3 
//  (1,4) (2,3)  -> d1 + d3 + d2 + d2
//  (1,3) (2,4)  -> d1 + d3 + d2 + d2 -> same delta with sapping
//  the argument is: to maximise delta, choose the max distance 
//
// NOTE: CLAIM (1): on a line with even points, the maximimal sum of distances can be done greedily by 
// 1. select the LEFT half of points as left
// 2. select the RIGHT half of the pointns as right 
// 3. arbitarily pair [LEFT,RIGHT] points
//
// PERF: idea
// 1. consider n/2 points as left , and n/2 points as right 
// 2. suppose D is the sum of distances given by the sum of deltas
// 3. we want all LEFT to be the first n/2 points on the line 
// 4. we want all RIGHT to be te last n/2 points on the line 
// 5. suppose we have n/2 pairs [LEFT,RIGHT]
// 6. if we choose R that is before a L : ie.  L R L R 
// 7. then we can greedily swap it from [R,L] -> [L,R] and gain the deltas from L ... R 
// 8. if we swap any Left+Left or Right+Right,  the deltas just get swapped them and the sum is the same
//
// this is quite useful claim, now we maximise dx, can we construct an answer that maximise dx + dy 
// suppose we separate Left, Right to maximise dx 
// then we can repeat the same strategy is for dy?? 
//
// (left) -> has a range of dy, symbol u
// (right) -> has a range of dy, symbol d
// lets sort them by y now 
// u d u u d u d d 
// actually, i realisd the "U" and "D" labels from dx doesnt matter?
// try random case: 
// u u d d  -> (1,3)(2,3) -> L L R R permitted
// u d d u  -> (1,3)(2,4) -> L L R R permitted
// suppose we have n red balls, n blue balls in an array, we can always pair left half to right half that is {red,blue} in a pair 
// the proof should be simple 
// for n=1 {red,blue} or {blue,red} tribial 
// for n > 1 
// suppose it is impossible , say on the left side si a BLUE 
// we cannot pair IFF all on the right is also BLUE, but contradicts since its n+1 blue, but the premise is n blue, n red
//
// NOTE: CLAIM (2): on a 2D plane, we can maxmis dx and dy sums 
// maximise dx by splitting left and right as described in claim (2) and label points and left, right
// then sort by y, and now pairs (left,right) or (right,left) since that the first item in pair is lower half of y, and second is upper half
// (proof of why this is possible is just above)
// then dy + dx is both maximised, and hence answer is maximised

void solve(){
    int n;
    cin >> n;
    vvl a(n, vl(3));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i; //idx
    }
    sort(all(a)); // sort by "x"
    set<int> left,right;
    for (int i = 0; i < n; i++){
        if (i < n/2) left.insert(a[i][2]);
        else right.insert(a[i][2]);
    }
    // now we need to sort by y axis
    for (int i = 0; i < n; i++) swap(a[i][0], a[i][1]);
    sort(all(a));
    vpi res;
    set<int> up_left, up_right;
    for (int i = n/2; i < n; i++){
        int id = a[i][2];
        if (left.count(id)) up_left.insert(id);
        else up_right.insert(id);
    }

    for (int i = 0; i < n/2; i++){
        int j = a[i][2];
        if (left.count(j)){
            auto it = up_right.begin();
            res.pb({j+1, *it+1});
            up_right.erase(*it);
        } else {
            auto it  = up_left.begin();
            res.pb({j+1, *it+1});
            up_left.erase(*it);
        }
    }
    for (auto& z: res) cout << z.F << " " << z.S << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
