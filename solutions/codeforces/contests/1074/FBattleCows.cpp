#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n' 
#define F first 
#define S second

template<class T>
struct SegTree{
    private:
        int n;
        vector<T> tree;
        T INVALID;

        T combine(T p, T q){
            return p ^ q;
        }

        void build(int low, int high, int pos, vector<T>& a){
            if (low==high){
                tree[pos] = a[low];
                return;
            }
            int mid = (high+low)/2;
            build(low,mid,2*pos+1,a);
            build(mid+1,high,2*pos+2,a);
            tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
        }

        // return win/lose outcome for n rounds 
        string update(int low, int high, int pos, int idx, T val){
            if (low == high){
                tree[pos] = val;
                return "";
            }

            int mid = (low+high)/2;

            string evl = "";
            bool is_left;

            if (idx <= mid){
                is_left = true;
                evl = update(low,mid,2*pos+1,idx,val);
            } else{
                is_left = false;
                evl = update(mid+1,high,2*pos+2,idx,val);
            }

            tree[pos] =  combine(tree[2*pos+1], tree[2*pos+2]);

            if (is_left){
                if (tree[2*pos+1] >= tree[2*pos+2]) evl += "W";
                else evl += "L";
            } else{
                if (tree[2*pos+2] > tree[2*pos+1]) evl += "W";
                else evl += "L";
            }
            return evl;

        }
    public:
        // === set invalid based on context == 
        SegTree(int size, T invalid = numeric_limits<T>::min()){
            n = size;
            INVALID=invalid;
            tree.resize(4*n,INVALID);
        }
        void build(vector<T>& a){ build(0,n-1,0,a); }
        string update(int idx, T val){return update(0,n-1,0,idx,val);}
};

void solve(){
    int n, q;
    cin >> n >> q;
    int len = (1 << n);

    vector<ll> a(len);

    for (auto& z:a) cin >> z;
    SegTree<ll> st(len, 0LL);
    st.build(a);

    while(q--){
        ll b,c;
        cin >> b >> c;
        b--; 
        string ans = st.update(b,c);
        ll pos = 0;
        for (int i =0; i < ans.size(); i++){
            if (ans[i] == 'L'){
                ll add = (1 << i );
                pos += add;
            }
        }

        cout << pos << endl;
        st.update(b, a[b]);
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
