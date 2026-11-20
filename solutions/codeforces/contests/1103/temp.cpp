#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <tuple>
#include <utility>
#include <numeric>
#include <functional>
#include <limits>
#include <climits>
#include <cassert>
#include <cstring>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;
 
typedef long long ll;
typedef pair<long long, long long> pll;
typedef tuple<long long, long long, long long> tll;
typedef tuple<long long, long long, long long, long long> qll;
typedef tuple<long long, long long, long long, long long, long long> qtll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;
typedef vector<vector<vector<long long> > > vvvll;
typedef vector<pair<long long, long long> > vpll;
typedef vector<vector<pair<long long, long long> > > vvpll;
typedef vector<tuple<long long, long long, long long> > vtll;
typedef vector<tuple<long long, long long, long long, long long> > vqll;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef map<ll, ll> mpll;
typedef unordered_map<ll, ll> umpll;
typedef priority_queue<ll> pqmaxll;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqminll;
typedef priority_queue<pll> pqmaxpll;
typedef priority_queue<pll, vector<pll>, greater<pll> > pqminpll;
 
const long long INF = 1000000000000000067;
const long long M1 = 998244353;
const long long M2 = 1000000007;
const long long M3 = 1000000009;
 
/*
//        _
//  _   _| |__
// | | | | '_ \
// | |_| | | | |
//  \__, |_| |_|
//  |___/         copyright
*/

void solve() {
	ll n;
	cin >> n;
	
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	vvll l(n+1, vll(n+1, -1)), r(n+1, vll(n+1, -1));
	vll curr(n+1, 0);
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		//cout << i << "\n";
		ll mi = a[i]; ll ma = a[i];
		fill(curr.begin(), curr.end(), 0);
		ll cnt = 0;
		
		for (ll j = i; j < n && (j - i + 1) <= (n/2); j++) {
			if (mi > a[j]) {
				mi = a[j];
			}
			if (ma < a[j]) {
				ma = a[j];
			}
			
			if (curr[a[j]] == 0) {
				curr[a[j]] = 1;
				cnt++;
			}
			
			//cout << "mi: " << mi << ", ma: " << ma << ", a[j]: " << a[j] << ", ";
			
			//cout << "cnt: " << cnt << "\n";
			
			if (cnt == ma-mi+1) {
                cerr <<  mi << " " << ma-mi+1 << " " << i << endl;
				r[mi][ma-mi+1] = i;
			}
			
			//cout << "round done\n";
		}
	}
	
	for (ll i = n-1; i >= 0; i--) {
		//cout << i << "\n";
		ll mi = a[i]; ll ma = a[i];
		fill(curr.begin(), curr.end(), 0);
		ll cnt = 0;
		
		for (ll j = i; j < n && (j - i + 1) <= (n/2); j++) {
			//cout << "mi: " << mi << ", ma: " << ma << ", a[j]: " << a[j] << "\n";
			if (mi > a[j]) {
				mi = a[j];
			}
			if (ma < a[j]) {
				ma = a[j];
			}
			
			if (curr[a[j]] == 0) {
				curr[a[j]] = 1;
				cnt++;
			}
			
			if (cnt == ma - mi + 1) {
                cerr <<  mi << " " << ma-mi+1 << " " << i << endl;
				l[mi][ma-mi+1] = i;
			}
			
			//cout << "round done\n";
		}
	}
    
	
	//cout << "done\n";
	
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n/2; j++) {
			
			if (i+j <= n && r[i+j][j] != -1 && l[i][j] != -1) {
				if (r[i+j][j] - l[i][j] >= j) {
					//cout << "i:" << i << "j: " << j << "\n";
					//cout << "r: " << r[i+j][j] << ", l: " << l[i][j] << "\n";
					ans = max(ans, j);
				}
			}
			
			if (i+j <= n && r[i][j] != -1 && l[i+j][j] != -1) {
				if (r[i][j] - l[i+j][j] >= j) ans = max(ans, j);
			}
		}
	}
	
	cout << ans << "\n";
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
