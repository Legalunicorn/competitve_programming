#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-08 00:31:21
File: bipartite_check
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:bipartite_check
bool check_bipartite(int u, vector<int>& color, vector<vector<int>>& g){
    //color ->{0: unassigne, 1: color one, 2: color two}
    int cur = color[u];
    int alt = 3 - cur;
    for (int v: g[u]){
        if (color[v]){
            if (color[v] != cur) return false;
        } else {
            color[v] = alt;
            if (!check_bipartite(v, color, g)) return false;
        } 
    }
    return true;
}
//END_SNIPPET:bipartite_check


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



