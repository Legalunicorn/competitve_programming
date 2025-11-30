#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-11-30 18:24:45
File: kmp
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/

struct kmp{

    vector<int> search(string text, string pat){
        int n = text.size(), m = pat.size();
        vector<int> lps(m);
        vector<int> res;
        construct(pat,lps);
        int i =0, j = 0;
        while(i<n){
            if (text[i]==pat[j]){
                i++;
                j++;
                if (j == n){
                    res.push_back(j-m);
                    j = lps[j-1];
                } else{
                    if (!j) j = lps[j-1];
                    else i++;
                }
            }
        }
        return res;
    }

private:
    void construct(string pat, vector<int>& lps){
        int len = 0, i =1;
        while (i< pat.size()){
            if (pat[i] == pat[len]){
                lps[i++] = ++len;
            } else{
                if (len) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
        
    }
};




// FOR TESTING 
void solve(){
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    return 0;
}