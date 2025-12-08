#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair


class SegTree{
public:
    SegTree(vector<int>& input, int n){
        this->input = input;
        //N is from cooridnates.size();
        this-> n = n;
        tree = vector<int>(n*4,0);

    }

    int query(int qlow, int qhigh){
        return queryUtil(qlow,qhigh,0,n-1,0);
    }

    void insert(int salary){
        updateUtil(0,n-1,0,salary,1);
    }
    //id -> index from input 
    void update(int id, int newSalary){
        int oldSalary = input[id];
        updateUtil(0,n-1,0,oldSalary,-1);
        updateUtil(0,n-1,0,newSalary,1);
        input[id] = newSalary;
    }

private:
    vector<int> tree;
    vector<int> input;
    int n;

    int queryUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow<=low && qhigh>=high){
            return tree[pos];
        }
        if (qlow>high || qhigh<low) return 0; 

        int mid = low + (high-low)/2;
        return (
            queryUtil(qlow,qhigh,low,mid,pos*2+1)+
            queryUtil(qlow,qhigh,mid+1,high,2*pos+2)
        );
    }

    void updateUtil(int low, int high ,int pos, int id, int delta){
        if (low==high){
            tree[pos]+=delta;
            return;
        }
        int mid = low + (high-low)/2;
        if (id<=mid){
            updateUtil(low,mid,2*pos+1,id,delta);
        } else{
            updateUtil(mid+1,high,2*pos+2,id,delta);
        }
        tree[pos] = tree[pos*2+1] + tree[pos*2+2];
    }
 
};

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> p(n);
    for (int& x:p) cin >> x;
    vector<tuple<char,int,int>> queries (q,tuple<char,int,int>());
    // vector<pair<int,int>> queries (q,pair<int,int>());

    for (int i=0;i<q;i++){
        char c; cin >> c ;
        int a,b; cin >> a >> b;
        queries[i] = {c,a,b};
        // queries.pb({c,a,b});
    }

    //Start the coordinate compressions 
    vector<int> coords;
    for (int& x:p) coords.pb(x);
    for (auto& x:queries){
        coords.pb(get<1>(x)); 
        coords.pb(get<2>(x));
    }
    sort(all(coords));
    //Print all
    // for (int x : coords) cout << x << " ";
    cout << endl;
    map<int,int> map;
    int id = 0;
    for (int i=0;i<coords.size();i++){
        if (i==0 || coords[i]!=coords[i-1]){
                // cout << coords[i] << " - " << id << endl;
                map[coords[i]] = id++;
        }
    }
    //change salary to mapped valyes


    //Create the seg tree 
    for (int& sal: p){
        sal = map[sal];
    }      
    SegTree st (p,coords.size());

    //populate frequency
    for (int sal: p){
        st.insert(sal);
    }    
    //run queries
    for (auto& t: queries){
        if (get<0>(t)=='!'){
            st.update(get<1>(t)-1,map[get<2>(t)]);
        } else{
            int low = map[get<1>(t)];
            int high = map[get<2>(t)];
            cout << st.query(low,high) << endl;
        }
        
    }

};
/*
we fill in values and store them first then process the mlate r
-> use a sum segment tree to store the frequency 
-> for each salaary p, we increment the node at "p"
-> 
*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
