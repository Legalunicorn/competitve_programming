#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;



struct KMP{
    vector<int> search(string text, string pat){
        int n = text.size(), m = pat.size();
        vector<int> lps(m), res;
        construct(pat,lps);
        int i =0, j = 0;
        while(i<n){
            if (text[i]==pat[j]){
                i++, j++;
                if (j == m){
                    res.push_back(i-j);
                    j = lps[j-1];
                } 
            } else{
                if (j!=0) j = lps[j-1];
                else i++;
            }
        }
        return res;
    }
private:
    void construct(string pat, vector<int>& lps){
        int len = 0, i =1;
        while (i< pat.size()){
            if (pat[i] == pat[len]){
                lps[i++] = ++len;
            } else{
                if (len) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
    }
};


// NOTE:
//
//
// 2025 cannot overlap 2025 SUBSTRING 
// for each i 
// NO 2025 
// YES 2026 
//
//
// "contain i" 
//
//
//
// NOTE: plan the impl first 
//
//


// ==== check combine function, update funciton, and default tree value 
// template<class T>
// struct SegTree{
// private:
//     int n;
//     vector<T> tree;
// 	T INVALID;
//     // === Change === 
//     T combine(T p, T q){
//         return max(p,q);
//     }
// 	void build(int low, int high, int pos, vector<T>& a){
// 		if (low==high){
// 			tree[pos] = a[low];
// 			return;
// 		}
// 		int mid = (high+low)/2;
// 		build(low,mid,2*pos+1,a);
// 		build(mid+1,high,2*pos+2,a);
// 		// check
//         tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
// 	}
//
// 	void q(int qlow, int qhigh, int low, int high, int pos, int v){
// 		if (qlow<= low && qhigh>=high) {tree[pos]+=v; return;}
// 		if (qlow> high || qhigh < low) return;
// 		int mid = low+(high-low)/2;
//         tree[pos] =  q(qlow,qhigh,low,mid,2*pos+1)+q(qlow,qhigh,mid+1,high,2*pos+2);
// 	}
// 	void up(int low, int high, int pos, int idx, T val){
//         // == =val or +=val 
//         if (low == high){
//             tree[pos] = val;
//             return;
//         }
//         int mid = (low+high)/2;
//         if (idx<=mid) up(low,mid,2*pos+1,idx,val);
//         else up(mid+1,high,2*pos+2,idx,val);
//         tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
// 	}
// public:
//     // === set invalid based on context == 
//     SegTree(int size, T invalid = numeric_limits<T>::min()){
// 		n = size;
// 		INVALID=invalid;
//       	tree.resize(4*n,INVALID);
//     }
// 	void build(vector<T>& a){ build(0,n-1,0,a); }
// 	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
// 	void update(int idx, T val){up(0,n-1,0,idx,val);}
// };

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 3){
        for (int i = 0; i < n;i++) cout << 0 << " ";
        cout << endl;
        return;
    }
    KMP kk;
    vi bad= kk.search(s,"2025");
    set<int> bs(all(bad));
    vi good= kk.search(s,"2026");
    vi diff(n+5, 0);
    for (int i= 0 ;i < n;i++){
        if (bs.count(i)) continue;
        auto ig = lower_bound(all(good),i);
        auto ib = lower_boundd(all(bad),i);
        int g = n-1, b= n-1;
        if (ig == good.end()) continue;
        if (ib != bad.end()) 
        if ()
        


    }
    // for each i see how far rightkk


   // for (int i =0; i < bad.size(); i++){
    //     if (i==0){
    //         if( b[i])
    //     }
    //     int r = bad[i]+2;
    // }
    // for (int i =0 ;i < n; i++){
    //     int bl = 0, br = n-1;
    //     auto it = lower_bound(all(bad), i);
    //     if (it != bad.begin()){
    //         it--; 
    //         bl = *it+1;
    //     }
    //     it = 
    // }



    // for (auto& z: badd) bad[z]=1;
    // for (auto& z: goodd) good[z]=1;
    // vpi left(n);
    // vpi right(n);
    // int p = 0;
    // for (int i = 0; i < n; i++){
    //
    // }


    


    // ll res = 0;
    // for (int i =0 ;i < n; i++){
    //     // is not inside a 2025
    //     bool skip = false;
    //     for (int p = 0;p < 4 ;p ++){
    //         bool ssss = false;
    //         int st = i-p;
    //         for (int q = 0; q < 4; q++){
    //             int pos = st+q;
    //             if (pos<0 || pos > 4) ssss= true;
    //         }
    //     }
    //
    //
    //     int bleft = 0, bright = n-1;
    //     auto it = lower_bound(all(bad),i);
    //     if (it == bad.begin()){  
    //         // no bad to the left
    //         if (*it > i) bleft = 0;
    //         else if (*it == i) bleft = n-1; // 
    //     } else{
    //         it--;
    //         int p  = *it+1; // skip the  "2" and we good
    //         bleft = p;
    //     }
    // }


    // for (int i = 0; i < n; i++){
    //     // 1. left and right bound of bad
    //     int bleft = 0, bright = n-1;
    //     bool skip = false;
    //     auto it = lower_bound(all(bad), i);
    //     if (it == bad.begin()){ // elemen
    //         if (*it > i) bleft = 0;
    //         else if (*it == i) skip = true;
    //         else {
    //
    //         }
    //     } else{
    //         it--; // go back
    //               //
    //     }
    //     // int bleft = 0, bright = n-1;
    //
    //     // intj
    //     {
    //         // BAD LEFT -> find largest b[i]
    //         int l = 0, r = bad.size();
    //         while(l <= r){
    //             int m = (l+r)/2;
    //             if ()
    //         }
    //     }
    // }




};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
