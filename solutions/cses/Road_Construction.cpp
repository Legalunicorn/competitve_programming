#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

//to add pbds 

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

int find(int a, vector<int>& parent);
void union_set(int a,int b, vector<int>& parent,vector<int>& size);


int max_union = 0;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> parent(n,0);
    vector<int> size(n,1);
    for (int i=1;i<n;i++) parent[i] = i;
    int comp = n;

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if (find(a,parent)!=find(b,parent)) {
            comp--;
            union_set(a,b,parent,size);

        }

        cout << comp << " " << max_union << endl;

    }
};



int find(int a, vector<int>& parent){
    if (parent[a]==a) return a;
    else return parent[a] = find(parent[a],parent);
}

void union_set(int a,int b, vector<int>& parent,vector<int>& size){
    a = find(a,parent);
    b = find(b,parent);
    if (a != b){
        if (size[a]<size[b]){
            swap(a,b);
        } // make sure a  > b
        parent[b] = a;
        size[a] += size[b];
        max_union = max(max_union,size[a]);
    }
}


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