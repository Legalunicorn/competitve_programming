#include <bits/stdc++.h>

#define ll long long
#define pq priority_queue
#define getString(n) getline(cin >> ws, n)

using namespace std;

void solve() {
    string s;
    getString(s);
    stack<char> st;
    set<char> seen;
    for (auto i: s) {
        if (seen.count(i)){
            cout << "No" << endl;
            return;
        }
        if (i == ')') {
            while (st.top() != '(') {
                seen.erase(st.top());
                st.pop();
            }
            st.pop();
        } else{ 
            if (i != '(')   seen.insert(i);
            st.push(i);
        }
    }
    cout << "Yes" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}


