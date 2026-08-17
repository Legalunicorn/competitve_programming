#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;


#define endl '\n' 

void solve(){
    int n = 60000;
    vl robot(n), spike(n);
    for (ll i =0; i < n; i++){
        robot[i] = i*4+1;
        spike[i] = robot[i]+1;
    }
       string s;
    for (int i =0; i < n;i++){
        if (i%2==0) s +="R";
        else s+="L";
    }

    cout << n << " " << n << " " << s.size();
    cout << endl;

    for (int i = 0; i < n; i++ ) {
        if (i) cout << ' ';
        cout << robot[i];
    }
    cout << endl;

    for (int i =0; i < n; i++){
        if (i) cout << ' ';
        cout << spike[i];
    }
    cout << endl;
    cout << s << endl;
};

int main(){

    int T = 1;

    cout << 1 << endl; 
    // cin >> T; 
    while(T--){
        solve();
    }
    return 0;
}
