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


void solve(int n) {
    int pile1 = 0; // The "Outbox" (TAKE from here)
    int pile2 = 0; // The "Inbox" (DROP here)

    for (int i = 0; i < n; i++) {
        string cmd;
        int m;
        cin >> cmd >> m;

        if (cmd == "DROP") {
            // Always drop into Pile 2
            cout << "DROP 2 " << m << endl;
            pile2 += m;
        } 
        else if (cmd == "TAKE") {
            // Step 1: Take what's already in Pile 1
            if (pile1 > 0) {
                int take_now = min(m, pile1);
                cout << "TAKE 1 " << take_now << endl;
                m -= take_now;
                pile1 -= take_now;
            }

            // Step 2: If we still need more, move everything from 2 to 1
            if (m > 0) {
                // The problem guarantees we won't TAKE more than exists on the table,
                // so if pile 1 is empty and we need more, they MUST be in pile 2.
                if (pile2 > 0) {
                    cout << "MOVE 2->1 " << pile2 << endl;
                    pile1 = pile2;
                    pile2 = 0;
                }

                // Step 3: Take the remaining amount from the newly filled Pile 1
                cout << "TAKE 1 " << m << endl;
                pile1 -= m;
            }
        }
    }
    // The problem requires an empty line between test cases
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(cin >> T && T != 0){
        solve(T);
    }
    cerr << " == END ==" << endl;
    return 0;
}
