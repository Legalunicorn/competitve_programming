#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    int n;
    cin >> s >> n;
    int size = 0;
    deque<string> q;
    string cmd;
    while(cin >> cmd){
        if (cmd == "push"){
            string x; cin >> x;
            q.push_front(x);
            size++;
            if (size > n) q.pop_back();
            cout << "null" << endl;
        } else{
            for (int i = q.size()-1;i >=0;i--){
                cout << q[i];
                if (i!=0) cout << " ";
            }
      
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();



    return 0;
}
