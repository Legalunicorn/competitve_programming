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
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//template/ template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // 
// template <class T> using ordered_multiset = tree<T, null_type,
// less_e

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


vector<bool> gen_sieve(int N){
    vector<bool> prime(N+1, true);    
    prime[0] =  prime[1] = false;
    for (int i = 2; i*i <= N ;i++){
        if (prime[i] && (ll)i*i <= N){
            for (int j=i*i; j<= N; j+=i){
                prime[j] = false;
            }
        }
    }
    return prime;
};

// use sieve to generate primes up to n 
vector<int> gen_primes(int n, vector<bool> primes){
    // vector<bool> primes = gen_sieve(n);
    vector<int> res;
    for (int i=2;i<=n;i++){
        if (primes[i]) res.push_back(i);
    }
    return res;
};

vector<int> prime_factors(int n,vb primes){
    int m = (int)ceil(sqrt(n+.01));
    vector<int> res;
    vector<int> prime_list = gen_primes(m, primes);
    for (int p: prime_list){
        if (p*p>n) break;
        while(n%p == 0){
            res.push_back(p);
            n /=p;
        }  
    }
    if (n>1){
        res.push_back(n);
    }
    return res;
}

/*


idea for brute force is there 

might improve with preprocessing maybe?


maybe there is some prunning trick

maybe when we insert -> sth

maybe lcm or gcd 


why does the algo go to n^2?

how can that happen? 



*/
void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a)); // small to large
    set<ll> st;
    set<ll> every;
    every.insert(a[0]);
    st.insert(a[0]);
    map<ll,ll> mul;
    mul[a[0]] = 1;
    // O(n) for a
    for (int i=1; i<n; i++){
        every.insert(a[i]);
        bool found = false;
        ll curr = a[i];
        for (ll x: st){
            if (curr%x==0){
                found = true;
                break;
            }
        }

        if (!found) {
            ll need = k/curr;
            if (need >= (n-i)){
                cout << -1 << endl;
                return;
            }
            st.insert(curr);
            mul[curr] = 1;
        } 
    }
    for (ll r: st){
        // cerr << "checking: " << r << endl;
        for (ll m = 2; m<=(n+3) && (r*m)<=k ;m++){
            ll x = r*m;
            // cerr << x << " ";
            if (!every.count(x)){
                cout << -1 << endl;
                return;
            }
        }
        // cerr << endl;
    }

    /*
    check the k limit condition? how
    mul[v] 
    */
    cout << st.size() << endl;
    for (auto x: st) cout << x << " ";
    cout << endl;
    // vb primes = gen_sieve(100005);
    
};

/*
    if B = A, it is perfectly fine 
    bi and bj can have common multiples

    the divisiors form a partial order
    we just take all the non comparable min elements it should be optimal
    how though? 
    get the prime facors

*/


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
