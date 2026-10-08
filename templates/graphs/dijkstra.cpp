#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2026-10-08 21:56:14
File: dijkstra
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:dijkstra
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &g, int s){
    using pll = pair<ll,ll>;
    ll inf  = (ll)4e18;
    int n = g.size();
    vector<ll> dist(n, inf);
    dist[s] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0ll,s});
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w) continue;
        for (auto [v, e]: g[u]){
            ll wt = w+e;
            if (wt < dist[v]){
                dist[v] = wt;
                pq.push({wt,v});
            }
        }
    }
    return dist;
};

//END_SNIPPET:dijkstra


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



