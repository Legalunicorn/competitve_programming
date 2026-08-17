#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using vi = vector<int>; using vvi = vector<vi>;
#define endl '\n' 

void solve(){
    string s,t;
    cin >> s >> t; 

    int n = s.size();
    int m = t.size();
    ll res = 0;
    int INVALID = n*5;

    // next[pos][char] = j
    // at position "i", the next time we see "char" is at index "j"
    // we use this to greedily search for subsequence of t 
    vvi next(n+1, vi(26, INVALID));
    for (int i = 0; i < n; i++){
        int v = s[i] - 'a';
        next[i][v] = i; // mark the position 
    }

    for (int i = n-1; i >= 0; i--){
        for (int c = 0; c < 26; c++){
            next[i][c] = min(next[i][c], next[i+1][c]);
        }
    }

    // for each starting position, find subsequence t as early as possible 
    // [start....end] -> contains "t"
    // then every substring from [start... (end-1)] does not contain "t"
    for (int i = 0; i < n; i++){
        int cur = i;  
        int ans = n -1;
        for (char x: t){
            int v = next[cur][x-'a']; // get the position;
            if (v == INVALID){
                cur = n + 1;
                break;
            }
            cur = v + 1;
        }
        res += (cur - i - 1);
    }
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
