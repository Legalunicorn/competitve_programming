/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */


#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;
using vvb = vector<vb>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;
constexpr double PI = 3.14159265358979323846;


// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define sortU (a) sort(all(a)),(a).erase(unique(all(a)),(a).end())

// === Debug macros , to add a general function and replace this gunk
#define debugv(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const vector<char> dir_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}

multiset<ll> lower, upper;

void balance() {
    while (lower.size() > upper.size() + 1) {
        auto it = prev(lower.end());
        upper.insert(*it);
        lower.erase(it);
    }
    while (upper.size() > lower.size()) {
        auto it = upper.begin();
        lower.insert(*it);
        upper.erase(it);
    }
}

void insert(ll x) {
    if (lower.empty() || x <= *prev(lower.end())) {
        lower.insert(x);
    } else {
        upper.insert(x);
    }
    balance();
}

void erase(ll x) {
    if (lower.find(x) != lower.end()) {
        lower.erase(lower.find(x));
    } else {
        upper.erase(upper.find(x));
    }
    balance();
}

ll get_median() {
    return *prev(lower.end());
}

void solve(){
    int n,k;
    cin >> n >> k;
    vvl a(n ,vl(n));
    for (int i=0;i<n;i++){
        for (int j=0; j<n ;j++){
            cin >> a[i][j];
        }
    }
    ordered_multiset<ll> st; 

    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            insert(a[i][j]);
        }
    }
    int pos = (k*k)/2; // o indexed?
    ll res = get_median(); 
    if (n==k){
        cout << res << endl;
        return;
    }
    ll gap = n -k; // the left right travel + total rows to go down 
    int top = 0;
    int bottom = k-1; // while bottom < n 
    int left = 0;
    int right = k-1;
    while(bottom < n){
        if (left==0){
            // cerr << "R " << endl;
            for (int step=0; step<gap ;step++ ){
                for (int r = top; r < top+k; r++){
                    erase(a[r][left]);
                }
                for (int r = top; r < top+k; r++){
                    insert(a[r][right+1]);
                }

                left++;
                right++; 
                ll evl = get_median();

                res = min(res,evl);
            }

        } else{

            for (int step=0; step<gap ;step++ ){

                for (int r = top; r < top+k; r++){
                    erase(a[r][right]);
                }
                // add right column 
                for (int r = top; r < top+k; r++){
                    insert(a[r][left-1]);
                }
                left--;
                right--;
                ll evl = get_median();
                res = min(res,evl);

            }
        }

        if (bottom == n-1) break;
        for (int c = left; c < left +k; c++){
            erase(a[top][c]);

        }
        for (int c = left; c < left+k; c++){
            insert(a[bottom+1][c]);
        }
        ll evl = get_median();
        res = min(res,evl);
        top++;
        bottom++;

    }
    cout << res << endl;

    
};

/*
what is the brute force ? 
800 * 800 = 640 000 

we want to find the median? we can use a pq of size cap 
this still sounds hella slow 

say n = 800 
k = 400 
(400)^2 * ()


maybe we can try DP 

as we "shift" the square most of the values dont change 
we can try to use this property but we need a way to kick out member 

PBDS should work right? 
so we initialise K by K 
then travel in a zig zag manner  
3 knds of transition : right, left, down 

use a boolean value to track left or right 
then for each of them have a down command 





*/



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
