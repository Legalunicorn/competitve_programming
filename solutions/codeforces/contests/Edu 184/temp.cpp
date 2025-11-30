#include <bits/stdc++.h>
using namespace std;

// ----------------------
//        MACROS
// ----------------------
#define ll long long
#define ld long double
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

// ----------------------   
//   CONSTANTS + UTILS
// ----------------------
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

// ----------------------
//       SOLVE
// ----------------------
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void solve() {
    // Write your solution logic here
    int n,a;
    cin>>n>>a;
    vi nums(n);
    rep(i,0,n){
        cin>>nums[i];
    }
    sort(all(nums));
    auto it=lower_bound(all(nums),a);
    int idx=it-nums.begin();
    if(n==1){
        if(a<nums[0]){
            cout<<a+1<<endl;
        }
        else if(a>nums[0]){
            cout<<a-1<<endl;
        }
        else{
            cout<<a<<endl;
        }
    }
    else{
        if(idx<n-idx-1){
        cout<<a+1<<endl;
        }
        else{
            cout<<a-1<<endl;
        }
    }
    
    
}

// ----------------------
//        MAIN
// ----------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);     // read input from input.txt
    freopen("output.txt", "w", stdout);   // write output to output.txt
#endif
    int t;
    cin >> t; // comment out if single test case
    while (t--) {
        solve();
    }

    return 0;
}
// g++ main.cpp -o main
// ./main
