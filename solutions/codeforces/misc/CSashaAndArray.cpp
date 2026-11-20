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

#define int long long
#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
// constexpr ll MOD = 1e9+7;

const int MAXN = 1e5, MOD = 1e9+7;

struct matrix{
    int M, N;
    int val[2][2];
};

int N, M , A[MAXN+5];
matrix base = {2, 2, 0, 1, 1, 1};
matrix iden = {2, 2, 1, 0, 0, 1};
matrix T;
matrix st[4*MAXN+5];
matrix lazy[4*MAXN+5];

matrix operator + (matrix a, matrix b){
    matrix c = a;
    for (int i = 0; i < c.M; i++){
        for (int j = 0; j < c.N; j++){
            c.val[i][j] += b.val[i][j];
            c.val[i][j] %= MOD;
        }
    }
    return c;
}

matrix operator * (matrix a, matrix b){
    matrix c;
    c.M = a.M, c.N = b.N;
    for (int i = 0; i < c.M; i++){
        for (int j = 0; j < c.N ; j++){
            c.val[i][j] = 0;
            for (int k = 0; k < a.N; k++){
                c.val[i][j] += a.val[i][k]*b.val[k][j];
            }
            c.val[i][j] %= MOD;
        }
    }
    return c;
}

// base ^ k 
matrix exp(int k){
    if (k == 0) return iden;
    matrix res = exp(k>>1);
    if (k&1) return (res*res)*base;
    return res*res;
}

//build(int id, int l, int r)
void build(int id, int l, int r){
    lazy[id]=iden;
    if(l==r){
        st[id].M = 1, st[id].N = 2;
        st[id].val[0][0] = 0, st[id].val[0][1] = 1;
        st[id] = st[id]*exp(A[l]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2]+st[id*2+1];
}
// update the child value, and its obligation to pass info down
void down(int id){
    st[id*2] = st[id*2]*lazy[id];
    st[id*2+1] = st[id*2+1]*lazy[id];
    lazy[id*2] = lazy[id*2]*lazy[id];
    lazy[id*2+1] = lazy[id*2+1]*lazy[id];
    lazy[id] = iden;
}
void update(int id, int l, int r, int u, int v){
    if (v < l || u > r) return;
    if (l >= u && r <= v){
        st[id] = st[id]*T;
        lazy[id] = lazy[id]*T;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id] = st[id*2]+st[id*2+1];
}
matrix get(int id, int l, int r, int u, int v){
    if (l>=u && r<=v) return st[id];
    down(id);
    int mid = (l+r)/2;
    if (v <= mid) return get(id*2,l,mid,u,v);
    else if (u>=mid+1) return get(id*2+1,mid+1,r,u,v);
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

void solve(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    build(1,1,N);
    while(M--){
        int type,l,r,x;
        cin >> type;
        if (type==1){
            cin >> l >> r >> x;
            T = exp(x);
            update(1,1,N,l,r);
        } else{
            cin >> l >> r;
            cout << get(1,1,N,l,r).val[0][0] << endl;
        }
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
