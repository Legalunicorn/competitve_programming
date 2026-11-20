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

// we need words used by EVERYONE 
// and then print them accordingly 
// we need a one passs 
// how do we mnow if a word is used by eveyrthin 
// if the ocunt of usage per persage = total number of persons 
// map<strin, people_used> 
// map<string, totla_count> 
//


vector<string> split(string& s, char delim){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delim)) tokens.push_back(token);
    return tokens;
}
void solve(){
    int n;
    cin >> n;
    cin.ignore(); // ignore the endln after "n"
    map<string, int > candidate; // -> their count 
    map<string, set<string>> person; 
    map<string,int> tot; // totla use count 


    for (int i = 0; i < n; i++){
        string str;
        getline(cin, str);
        vector<string> words = split(str, ' ');
        string u = words[0];
        for (int i = 1; i < words.size(); i++){
            if (!person[u].count(words[i])){
                candidate[words[i]]++;
                person[u].insert(words[i]);
            }
            tot[words[i]]++; // total usage count 
        }
    }
    
    vector<pair<int, string>> res;
    for (auto& [val, cnt]: candidate){
        if (cnt == person.size()) res.pb({tot[val], val});
    }

    sort(res.rbegin(), res.rend());
    sort(all(res), [&](const auto& p, const auto& q){
        if (p.F == q.F){
            return p.S < q.S;
        }
        return p.F > q.F;
    });
    if (res.size() == 0){
        cout << "ALL CLEAR";
        return;
    }
    for (auto& [a,b]: res) cout << b << endl;


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
