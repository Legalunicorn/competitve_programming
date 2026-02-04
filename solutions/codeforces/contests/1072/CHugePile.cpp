#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int x=INT_MAX,limit;
        for (int i=2;i<=n;i++){
            if ((n-i)!=1 && (2*i-n)>=0){
                x=min(x,(2*i-n));
            }
        }
        cout << x << endl;
    }
}
