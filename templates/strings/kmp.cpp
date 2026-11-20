#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2026-05-29 01:08:07
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


//SNIPPET_ID:kmp
struct KMP{
    vector<int> search(string text, string pat){
        int n = text.size(), m = pat.size();
        vector<int> lps(m), res;
        construct(pat,lps);
        int i =0, j = 0;
        while(i<n){
            if (text[i]==pat[j]){
                i++, j++;
                if (j == m){
                    res.push_back(i-j);
                    j = lps[j-1];
                } 
            } else{
                if (j!=0) j = lps[j-1];
                else i++;
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



//END_SNIPPET:kmp


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



