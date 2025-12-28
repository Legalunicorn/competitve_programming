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


// its not just a 26 base conversion isnt it? 
// A-Z
// A(A-Z)
// 27 + 16

void solve(){
    string s;
    cin >> s;
    // a letter always prefix a number 
    int n = s.size();
    int cnt = 0;
    int first = -1;
    int last = 0;
    for (int i=1; i<n;i++){
        if (isdigit(s.at(i)) && !isdigit(s.at(i-1))){
            cnt++;
            if( first == -1) first = i;
            last = i;
        }
    }
    // cerr << "f --> " <<   first << " " << last << endl;
    if (cnt==1){ // we are dealing with type 1 
        // cerr << "one!" << s << endl;
        string col = s.substr(0,last);
        reverse(all(col));
        int row = stoi(s.substr(last));

        int val  =0;
        for (int i=0; i<col.size(); i++){
            int id = col[i]-'A'+1;
            val += id * (int) pow(26,i);
        }
        // int val = 0;
        // int i
        // for (int i=0;i<col.size();i++){
        //     int mul = col[i] -'A';
        //     val += 
        //     // cerr << "mul: " << mul << endl;
        //     val += mul*(int)pow(27,i);
        // }
        // // if (val <26) val++;
        cout << "R" << row << "C" << val << endl;

    } else{
        int row = stoi(s.substr(1,last));
        int col = stoi(s.substr(last));
        // cerr << "col: " << col << endl;
        // cerr << row << " " << col << endl;
        string ans;
        int pow = 0;
        while(col>0){
            ans +=  (char)((col -1)  % 26 + 65);
            col = (col-1)/26;
            // int r = col%26;
            // ans += (char)(r+'A');
            // col /=26;
            // cerr << "c val: " << col << endl;
            // int rem = col % 26;
            // // cerr << rem << endl;
            // int v = (rem - 1 + 26 ) % 26;
            // // ans += (char)(v+'A');
            // if (rem == 0){
            //     ans += 'Z';
            //     int m = col/26;
            //     if (m-2 >= 0) ans += (char)(m -2 + 'A'); 
            //     col /=26;
            // } else{
            //     ans += (char)(rem -1 + 'A');
            // }
            //
            // col /= 26;

        }
        reverse(all(ans));
        cout << ans << row << endl;
        
        // convrt col to alphabets

    }
    cerr << " ===================== " << endl;
};
// 52 
// 52  / 26 = 2 
// BZ 
// "B" 


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
