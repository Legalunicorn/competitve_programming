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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;



// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q){
        vi table(26);
        for (int i = 0; i < 26;i++){
            table[i] = p[i] + q[i];
        }
        return table;
    }
	void build(int low, int high, int pos, vector<T>& a){
		if (low==high){
			tree[pos] = a[low];
			return;
		}
		int mid = (high+low)/2;
		build(low,mid,2*pos+1,a);
		build(mid+1,high,2*pos+2,a);
		// check
        tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
	}

	T q(int qlow, int qhigh, int low, int high, int pos){
		if (qlow<= low && qhigh>=high) return tree[pos];
		if (qlow> high || qhigh < low) return INVALID;
		int mid = low+(high-low)/2;
        return combine(
            q(qlow,qhigh,low,mid,2*pos+1),
            q(qlow,qhigh,mid+1,high,2*pos+2)
                );
	}
	void up(int low, int high, int pos, int idx,  int val, int id2 ){
        // == =val or +=val 
        if (low == high){
            tree[pos][id2] = val;
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) up(low,mid,2*pos+1,idx,val,id2);
        else up(mid+1,high,2*pos+2,idx,val,id2);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
	}
public:
    // === set invalid based on context == 
    SegTree(int size, T invalid = numeric_limits<T>::min()){
		n = size;
		INVALID=invalid;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, int  val,int id2){up(0,n-1,0,idx,val,id2);}
};




vector<string> split(string s,string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        vb res;
        vvi g(n);
        for (int i = 0; i < edges.size() ; i++){
            int u = edges[i][0], v = edges[i][1];
            g[u].pb(v);
            g[v].pb(u);
        }
        int order_idx = 0;
        vi order_in(n+1), order_out(n+1);
        auto dfs = [&](auto& dfs, int u , int p) -> void{

            order_in[u] = order_idx++;
            for (int v: g[u]){
                if (v == p) continue;
                dfs(dfs, v,u);
            }
            order_out[u] = order_idx;
        };

        dfs(dfs,0,-1);
        SegTree<vector<int>> st(n, vi(26,0));
        for (int i = 0; i < n; i ++){
            int pos = (int)(s[i] - 'a');
            st.update(order_in[i], 1, pos);
            st.update(order_out[i], -1, pos);
        }

        //
        for (int q = 0; q < queries.size(); q++ ){
            string qq = queries[q];
            vector<string> arr = split(qq," ");
            if (arr[0] == "update"){
                int u = stoi(arr[1]);
                int old = (s[u] - 'a');
                int id = (char)(arr[2][0]) -'a';

                st.update(order_in[u], -1 ,old);
                st.update(order_out[u], 1, old);
                s[u] = arr[2][0];
                st.update(order_in[u], 1, id);
                st.update(order_out[u], -1, id);

            } else {
                int cnt = 0; 
                int u = stoi(arr[1]);
                int v = stoi(arr[2]);
                vi one = st.query(0, order_in[u]);
                vi two = st.query(0, order_in[v]);
                for (int i = 0; i < 26;i++){
                    int d = abs(one[i] - two[i]);
                    if (d%2==1) cnt++;
                }
                if (cnt <=1) res.pb(true);
                else res.pb(false);
            }
        }

        return res;
    }
};


void solve(){
    
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
