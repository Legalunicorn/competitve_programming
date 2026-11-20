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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE:
// for each number binary search for x -2 , x + 2
// d(i, j) i <= j
//
// d(i,j) 
// -> -i + j 
// the sum of j, and minus calls of i 
//
// coordinates compression from 10e9 to 10e5 
// theen we use a frequency segment tree 
// x , x-1 x+1 
// the maintain the sum
//
using  int128 =   signed __int128;
using uint128 = unsigned __int128;
 
namespace int128_io {
 
	inline auto char_to_digit(int chr) {
	    return static_cast<int>(isalpha(chr) ? 10+tolower(chr)-'a': chr-'0'); }
 
	inline auto digit_to_char(int digit) {
    	return static_cast<char>(digit > 9 ? 'a'+digit-10: '0'+digit); }
 
	template<class integer>
	inline auto to_int(const std::string &str, size_t *idx = nullptr, int base = 10) {
		size_t i = idx != nullptr ? *idx : 0;
		const auto n = str.size();
		const auto neg = str[i] == '-';
		integer num = 0;
		if (neg)
			++i;
		while (i < n)
			num *= base, num += char_to_digit(str[i++]);
		if (idx != nullptr)
			*idx = i;
		return neg ? -num : num; }
 
	template<class integer>
	inline auto to_string(integer num, int base = 10) {
		const auto neg = num < 0;
		std::string str;
		if (neg)
			num = -num;
		do
			str += digit_to_char(num%base), num /= base;
		while (num > 0);
		if (neg)
			str += '-';
		std::reverse(str.begin(),str.end());
		return str; }
 
	inline auto next_str(std::istream &stream) { std::string str; stream >> str; return str; }
 
	template<class integer>
	inline auto& read(std::istream &stream, integer &num) {
		num = to_int<integer>(next_str(stream));
		return stream; }
 
	template<class integer>
	inline auto& write(std::ostream &stream, integer num) { return stream << to_string(num); } }
 
using namespace std;
 
inline auto& operator>>(istream &stream,  int128 &num) { return int128_io::read(stream,num); }
inline auto& operator>>(istream &stream, uint128 &num) { return int128_io::read(stream,num); }
inline auto& operator<<(ostream &stream,  int128  num) { return int128_io::write(stream,num); }
inline auto& operator<<(ostream &stream, uint128  num) { return int128_io::write(stream,num); }
 
inline auto uint128_max() {
	uint128 ans = 0;
    for (uint128 pow = 1; pow > 0; pow <<= 1)
		ans |= pow;
    return ans; }
 
void solve(){
    int n;
    cin >> n;
    vector<__int128> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<__int128,int> mp;
    __int128 sum = a[n-1];
    __int128 res = 0;
    mp[a[n-1]]++;
    for (int i = n -2; i >= 0; i--){
        __int128 tot = n - i -1 ; // how many we seen so far;
        __int128 ts = sum;
        __int128  x = a[i];
        tot -= mp[x];
        ts -= mp[x] * x;
        tot -= mp[x-1];
        ts -= mp[x-1] * (x-1);
        tot -= mp[x+1];
        ts -= mp[x+1] * (x+1);
        __int128 add = ts;
        __int128 minus = x * tot;
        res = res + add - minus;
        sum += x;
        mp[x]++;

    }
    cout << res;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("ww__","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
