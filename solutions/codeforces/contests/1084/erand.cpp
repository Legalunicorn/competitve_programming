/*
    || साम्ब-सदाशिव ||

    author: viplove tyagi i.e. @mox.

    the template and code snippets used, if any, have been taken from: -
	
    my repository: https://github.com/vipplovve/TemplateVault
*/

#include <bits/stdc++.h>
using namespace std;

using str = string;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 4e18;
const ld EPS = 1e-10;

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define TimeTaken cerr << "Execution Took: " << 1000 * clock() / CLOCKS_PER_SEC << " ms." << endl;
#define Precise cout << fixed << setprecision(15); 

#define testcase(n) while(n--)

#define yeah(capital) cout << ((capital) ? "YES\n" : "Yes\n")
#define nah(capital) cout << ((capital) ? "NO\n" : "No\n")
#define measure(container) int(container.size())

#define endl '\n'
#define flushin cout << flush

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()

#define setbits(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_ctz(x)

#define RandomInt(left, right) uniform_int_distribution<ll> (left, right)(RNG)
#define RandomDouble(left, right) uniform_real_distribution<ld> (left, right)(RNG)

int main()
{
    FastIO
    
    // The Code's Here.

    ll t;

    cin >> t;

    vector<ll> factors(1e6 + 1, 0);

    factors[1] = 1;

    for(ll x = 2; x <= 1e6; x++)
        if(!factors[x])
        {
            factors[x] = x;

            for(ll y = x * x; y <= 1e6; y += x)
                if(!factors[y])
                    factors[y] = x;
        }

    testcase(t)
    {
        ll n;

        cin >> n;

        vector<ll> data(n);

        for(ll x = 0; x < n; x++)
            cin >> data[x];

        vector<ll> modified;

        bool possible = false;

        for(ll x = 1; x < n; x++)
            if(data[x] < data[x - 1])
                possible = true;

        str answer = "";

        if(!possible)
            answer = "Bob";
        else
        {
            for(ll x = 0; x < n; x++)
            {
                ll current = data[x];

                if(factors[current] == current)
                    modified.push_back(current);
                else
                {
                    vector<ll> left, right;

                    bool move = true;

                    while(current != 1)
                    {
                        if(move)
                            right.push_back(factors[current]);
                        else
                            left.push_back(factors[current]);

                        current /= factors[current];
                        move ^= 1;
                    }

                    reverse(all(right));

                    for(auto i : left)
                        modified.push_back(i);

                    for(auto i : right)
                        modified.push_back(i);
                }
            }

            bool valid = false;

            for(ll x = 1; x < measure(modified); x++)
                if(modified[x] < modified[x - 1])
                    valid = true;

            if(valid)
                answer = "Alice";
            else
                answer = "Bob";
        }

        cout << answer << endl;
    }

    TimeTaken

    return 0;
}
