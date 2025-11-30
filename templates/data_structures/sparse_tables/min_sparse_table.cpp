#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-11-30 16:45:46
File: min_sparse_table
Tested: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/

template<class T>
struct SparseTable{
public:

    SparseTable(int size){
        n = size;
        logPow.resize(n+1,0);
        for (int i=2;i<=n;i++) logPow[i] = logPow[i/2]+1;
        while((1<<LOG)<+n) LOG++;
        st.resize(n, vector<T>(LOG));
    }

    void build(vector<T>& arr){
        for (int i=0; i<n; i++){
            st[i][0] = arr[i];
        }
        for (int j=1; j<LOG; j++){
            for (int i=0; i + (1<<j) - 1 < n; i++){
                T a = st[i][j-1];
                T b = st[i+(1<<(j-1))][j-1];
                
                // CHECK
                st[i][j] = min(a,b);
            }
        }
    }
    
    int query(int l, int r){
        int k = logPow[r-l+1];
        T a = st[l][k];
        T b = st[r-(1<<k)+1][k];

        // CHECK
        return min(a,b);
    }
private:
    vector<vector<T>> st;
    int LOG = 20;
    int n;
    vector<int> logPow;
};








// FOR TESTING 
// void solve(){
//     int n,q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (auto& z:a) cin >> z;
//     SparseTable<int> st(n);
//     st.build(a);
//     while(q--){
//         int l,r;
//         cin >> l >> r;
//         cout << st.query(l-1,r-1) << endl;
//     }
// };


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int T =1;
//     // cin >> T; 
//     while(T--){
//         solve();
//     }
//     return 0;
// }
