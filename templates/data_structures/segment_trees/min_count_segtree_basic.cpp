#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-11-30 19:04:03
File: min_count_segtree_basic
Author: github@legalunicorn
Test status: basic test
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/

template<class T>
struct SegTree{
private:
    int n;
    vector<pair<T,int>> tree;
	pair<T,int> INVALID;

    pair<T,int> combine(pair<T,int> p, pair<T,int> q){
        if (p.first == q.first) return {p.first, p.second+q.second};
        else if (p.first < q.first) return p;
        else return q;
    }

	void build(int low, int high, int pos, vector<T>& a){
		if (low==high){
			tree[pos] = {a[low],1};
			return;
		}
		int mid = (high+low)/2;
		build(low,mid,2*pos+1,a);
		build(mid+1,high,2*pos+2,a);
		// check
		tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
	}

	pair<T,int> q(int qlow, int qhigh, int low, int high, int pos){
		if (qlow <= low && qhigh>=high) return tree[pos];
		if (qlow > high || qhigh < low) return INVALID;
		int mid = low+(high-low)/2;
		return combine(
			q(qlow,qhigh,low,mid,2*pos+1),
			q(qlow,qhigh,mid+1,high,2*pos+2)
		);
	}

	void up(int low, int high, int pos, int idx, T val){
		if (low==high) {
			tree[pos] = {val,1};
			return;
		}
		int mid = (low+high)/2;
		if (idx<=mid) up(low,mid,2*pos+1,idx,val);
		else up(mid+1,high,2*pos+2,idx,val);
		// check
		tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
	}
	
public:
	// check
    SegTree(int size, T invalid = numeric_limits<T>::max ()){
		n = size;
		INVALID={invalid,0};
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	pair<T,int> query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};






// FOR TESTING 
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& z:a) cin >> z;
    SegTree<int> st(n);
    st.build(a);
    while(q--){
        int l,r;
        cin >> l >> r;
        pair<int,int> res = st.query(l-1,r-1);
        cout << res.first << " " << res.second << endl;

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