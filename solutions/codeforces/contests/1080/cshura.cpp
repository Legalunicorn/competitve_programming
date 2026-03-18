
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vll = vector<long long>;
using vb = vector<bool>;
using vin = vector<int>;
using pll = pair<ll, ll>;
using mpll = map<ll, ll>;
using umll = unordered_map<ll, ll>;
using sl = set<ll>;
using usl = unordered_set<ll>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f(i, x, n) for (int i = (x); i < (n); i++)
const ll INF = 1e18;

void solve()
{
    ll n; 
    cin >> n;
    vll a(n);
    f(i,0,n) cin >> a[i];
    vll change(7, INF);

    f(x, 1, 7)change[x] = (a[0] != x);

    f(i, 1, n) {
        vll newC(7, INF);
        f(x, 1, 7) { 
            f(y, 1, 7) {      
                if((x != y && x + y != 7)){
                    newC[x] = min(newC[x], change[y] + (a[i]!=x));
                }
            }
        }
        change = newC;
    }

    cout << *min_element(change.begin()+1, change.end()) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) solve();
}
