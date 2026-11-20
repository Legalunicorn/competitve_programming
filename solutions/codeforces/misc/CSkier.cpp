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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

int tc =0;
void solve(){
    tc++;
    int time = 0;
    set<pair<pi,pi>> st;
    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    int x2,y2;


    for (int i=0;i<s.size();i++){
        char c= s[i];
        x2 = x;
        y2 = y;
        if (c=='N') y2++;
        else if (c=='S') y2--;
        else if (c=='E') x2--;
        else x2++;
        if (st.count({{x,y},{x2,y2}}) || st.count({{x2,y2},{x,y}})) time++;
        else time += 5;
        st.insert({ {x,y},{x2,y2} });
        x = x2;
        y = y2;
    }
    cout << time << endl;


    // st.insert({0,0});
    // for (char c: s){
    //     if (c=='N') y++;
    //     else if (c=='S') y--;
    //     else if (c=='E') x--;
    //     else x++;
    //     if (st.count({x,y,c-'A'})) time ++;
    //     else time += 5;
    //     st.insert({x,y,c-'A'});
    // }
    // cout << time << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
