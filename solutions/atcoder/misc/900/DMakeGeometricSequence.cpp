/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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



void solve(){
    // sort by real values?
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& z:a) cin >> z;
    set<ll> st;
    for (int i=0;i<n;i++) st.insert(abs(a[i]));
    if (st.size()==1){
        int pos = 0, neg =0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) neg++;
            else pos++;
        }
        if (pos == n || neg == n ){
            cout << "Yes" << endl;
        } else {
            if (n%2==0){
                if (pos == neg) cout << "Yes" << endl;
                else cout << "No" << endl;
                return;
            } else{
                if (pos == neg+1 || neg == pos+1){
                    cout << "Yes" << endl;
                } else cout << "No" << endl;
                return;
            }
        }
        return;
    }
    if ((int)(st.size())<n){ // this is not true, -6 
        cout << "No" << endl;
        return;
    }

    sort(all(a),[&](const auto& p, const auto& q){
           return abs(p) > abs(q); 
    });
    // debugv(a);
    // real number 
    // ld r = a[1]/a[0];
    // dont use division
    for (int i=2;i<n;i++){
        // (a/b) = (b/c) 
        //  a*c  = b*b
        ll left = a[i]*a[i-2];
        ll right = a[i-1]*a[i-1];
        if (left!=right){
            cout << "No" << endl;
            return;
        }
    }
    // cerr << to_string(r) << endl;
    // for (int i=1;i<n;i++){
    //     ld c = a[i]/a[i-1];
    //     if (abs(r-c)> (ld)(1e-4)){
    //         cout << "No" << endl;
    //         return;
    //     }
    // }
    cout << "Yes" << endl;
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
