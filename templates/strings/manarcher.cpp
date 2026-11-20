#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2026-05-14 02:27:01
File: manarcher
Author: taken from cp algorihims
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:manarcher

// HELPER METHOD
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        if(i <= r) p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) { p[i]++;}
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) t += string("#") + c;
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
//END_SNIPPET:manarcher


// FOR TESTING 
void solve(){
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    return 0;
}



