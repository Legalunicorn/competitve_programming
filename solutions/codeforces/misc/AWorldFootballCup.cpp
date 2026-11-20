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

void solve(){
    int n;
    cin >> n;
    int v = n*(n-1)/2;
    vector<string> a(n);
    vi points(n,0),scored(n,0), missed(n,0);

    // wtf is missed goals 
    map<string,int> mp;
    for (int i=0;i<n;i++){
        string s; cin >> s;
        a[i] = s;
        mp[s] = i;
    }
    for (int i=0;i<v;i++){
        string who; cin >> who;
        int pos = 0;
        for (int i=0;i<who.size();i++){
            if (who[i]=='-') {
                pos = i;
                break;
            }
        }
        string one = who.substr(0,pos);
        string two = who.substr(pos+1);

        int t1 = mp[one];
        int t2 = mp[two];


        string score;  cin >> score;
        int dash = 0;
        for (int i=0;i<score.size();i++){
            if (score[i]==':'){
                dash = i;
                break;
            }
        }
        string s1 = score.substr(0,dash);
        string s2 = score.substr(dash+1);
        int score1 = stoi(s1), score2= stoi(s2);

        if (score1==score2){
            points[t1]++;
            points[t2]++;
        } else if (score1 > score2){
            points[t1]+=3;
        } else {
            points[t2] += 3;
        }
        scored[t1] += score1;
        scored[t2] += score2;
        missed[t1] += score2;
        missed[t2] += score1;


    }
    vi diff(n,0);
    for (int i=0;i<n;i++){
        diff[i] = scored[i] - missed[i];
    }

    sort(all(a), [&](const auto& p, const auto& q){
        int x = mp[p], y = mp[q];
        if (points[x] ==  points[y]){
            if (diff[x] != diff[y]){
                return diff[x]  > diff[y];
            } else{
                return scored[x] > scored[y];
            }
        } else{
            return points[x] > points[y];
        }
    });

    for (int i=0;i<n;i++){
        debug(a[i], points[i], scored[i], diff[i]);
    }

    vector<string> best(n/2);
    for (int i=0;i<n/2;i++){
        best[i] = a[i];
    }
    sort(all(best));
    for (auto& z: best) cout << z << endl;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
