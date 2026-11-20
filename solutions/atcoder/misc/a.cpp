#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s;
    string res;
    vector<int> ans = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    for (int i = 0; i < N ; i++){
        cin >> s;
        int a = s[0];
        for (int i = 0; i < 26;i++){
            if (s[0] -'a' == i)  res += to_string(ans[i]);
        }
    }
    cout << res << endl;
}
