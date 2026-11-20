#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-07 01:25:12
File: coordinate_compression
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


// One mapping 
//SNIPPET_ID:coord_compression_one
template<typename T>
map<T,int> coord_compress(vector<T>& arr){
    int id = 0;
    set<T> st(arr.begin(),arr.end());
    map<T,int> mp;
    for (const auto& x: arr) mp[x] = id++;
    return mp;
};
//END_SNIPPET:coord_compression_one




// Return two mapping 
//SNIPPET_ID:coord_compression_both
template<typename T>
pair<map<T,int>,map<int,T>> coord_compress_both(vector<T>& arr){
    int id =0;
    set<T> st(arr.begin(),arr.end());
    map<T,int> mp;
    map<int,T> pm;
    for (const auto& x: arr){
        mp[x] = id;
        pm[id++] = x;
    }
    return {mp,pm};
};
//END_SNIPPET:coord_compression_both



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




