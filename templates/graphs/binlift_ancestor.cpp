#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-31 00:54:19
File: binlift_ancestor
Author: errichto
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:binlift_ancestor
// Binary Lifting tutorial https://youtu.be/oib-XsjFa-M
class TreeAncestor {
    vector<vector<int>> up; // int up[N][20];
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, int root, vector<vector<int>> g){
        vector<int> par(n);
        auto dfs = [&](auto& dfs, int u, int p)-> void{
            par[u] = p;
            for (auto& v: g[u]){
                if (v==p) continue;
                dfs(dfs,v,u);
            }
        };
        dfs(dfs, root, -1);
        TreeAncestor(n, par);
    }

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        // up[v][j] is 2^j -th ancestor of node v
        parent[0] = 0;
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];
            if(v != 0) {
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = LOG - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};
//END_SNIPPET:binlift_ancestor


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



