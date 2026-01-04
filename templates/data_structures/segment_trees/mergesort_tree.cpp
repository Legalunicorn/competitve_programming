#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
Created: 2025-12-30 04:03:42
File: mergesort_tree
Author: https://discuss.codechef.com/t/merge-sort-tree-tutorial/14277
Test status: 
Description: UNTESTED 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:mergesort_tree_simple
const int MST = 1e5+5;
template<class T>
struct SegTree{
    vector<T> tree[5*MST];

    void build(int pos, int l, int r, vector<T>& a){
        if (l==r){
            tree[pos].pb(a[l]);
            return;
        }
        int mid = l+(r-l)/2;
        build(2*pos+1,l,mid);
        build(2*pos+2,mid+1,r);
        tree[pos] = merge(tree[2*pos+1],tree[2*pos+2]);
    }
    // query count smaller than k
    int helper_query_min(int pos, int l, int r, int x, int y, int k){
        if (r < x || l > y) return 0;
        if (x<=l && r <= y) return lower_bound(tree[pos].begin(),tree[pos].end(),k) - tree[pos].begin();
        int mid = l+(r-l)/2;
        return helper_query_min(2*pos+1,l,mid,x,y,k)+helper_query_min(2*pos+2,mid+1,r,x,y,k);
    }
};
//END_SNIPPET:mergesort_tree_simple


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



