#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-07 21:37:06
File: dsu_basic
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:dsu_basic
struct Dsu{
private:
    int n; 
    vector<int> par, size;
public:
    Dsu(int sz){
        n = sz;
        size.assign(n,0);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};

//END_SNIPPET:dsu_basic


// FOR TESTING 
void solve(){
    // size of arr, input of elements 
    // q join commands 
    // k check commands 
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int q; cin >> q;
    cerr << "ok 1" << endl;
    Dsu dsu(n);
    for (int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        dsu.union_set(a-1,b-1);
    }
    cerr << "ok 2 " << endl;
    int k; cin >> k;
    for (int i=0; i<k; i++){
        int a,b; cin >> a >> b;
        a = dsu.find(a-1);
        b = dsu.find(b-1);
        if (a==b) cout << "yes" << endl;
        else cout << "no" << endl;
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



