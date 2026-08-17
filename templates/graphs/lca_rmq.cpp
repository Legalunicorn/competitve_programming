#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-31 00:54:19
File: lca_rmq
Author: github@legalunicorn 
Test status: passed: https://www.spoj.com/submit/LCA/  
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:lca_rmq
struct Tree{
    int n,timer, LOG;
    vector<int> tin, euler_tour, logPow, depth;
    vector<vector<int>> g,st;

    Tree(int sz): timer(0), n(sz), tin(n,0), euler_tour(2*n,0), depth(n,0){
        g.assign(n, vector<int>());
        logPow.assign(2*n+1,0);
        for (int i=2;i<2*n+1;i++) logPow[i] = logPow[i/2]+1;
    }
    // Sprase table functions 
    int combine(int a, int b){
        return (tin[a] < tin[b] ? a : b);
    }
    void st_build(){
        for (int i=0; i<timer; i++) st[i][0] = euler_tour[i];
        for (int j=1; j<LOG; j++){
            for (int i=0; i + (1<<j) <= timer; i++){
                int a = st[i][j-1];
                int b = st[i+(1<<(j-1))][j-1];
                st[i][j] = combine(a,b);
             }
        }
    }    
    int st_query(int l, int r){
        int k = logPow[r-l+1];
        int a = st[l][k], b = st[r-(1<<k)+1][k];
        return combine(a,b);
    }
    // End of sparse table functions 

    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // called from build
    void dfs(int u = 0, int p = -1, int d = 0){
        depth[u] = d;
        tin[u] = timer;
        euler_tour[timer++] = u;
        for (int v:g[u]){
            if (v == p) continue;
            dfs(v,u,d+1);
            euler_tour[timer++] = u;
        }
    }

    void build(int u = 0, int p = -1){
        dfs(u,p);
        LOG = 0;
        while((1<<LOG)<=timer) LOG++;
        st.resize(timer, vector<int>(LOG));
        st_build();
    }

    int lca(int a, int b){
        if (tin[a]>tin[b]) swap(a,b);
        return st_query(tin[a], tin[b]);
    }

    int dist(int a, int b){ return depth[a] + depth[b] - 2*depth[lca(a,b)];}

};

//END_SNIPPET:lca_rmq


// FOR TESTING 
void solve(){
    int n,q;
    cin >> n >> q;
    Tree tree(n);
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        tree.add_edge(u-1, v-1);
    }
    tree.build();
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << tree.lca(a-1,b-1)+1 << endl;
    }


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



