class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 1, r = n;
        int res = 0;
        auto pos = [&](int x) -> bool {
            // we iterate for each alphab et
            for (int c = 0; c < 26; c++){
                int cnt = 0;
                for (int i = 0; i < n;i++){
                    if (s[i]-'A' == c) cnt++;
                    if (i - x >= 0) {
                        if (s[i-x]-'A' == c) cnt--;
                    }
                    if (cnt + k >= x) return true;
                }
            }
            return false;
        };
        while(l<=r){
            int m = (l+r)/2;
            if (pos(m)){
                res = m;
                l = m + 1;
            } else r = m -1;
        }
        return res;
    }
};
