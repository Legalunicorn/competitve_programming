#include <bits/stdc++.h>
using namespace std;
long long nCr[64][64];
void precompute()
{
    for (int i = 0; i < 64; i++) 
    {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; j++)
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
}
long long countWithSetBits(long long n, int k) 
{
    if (k < 0 || k > 60) return 0;
    long long res = 0;
    for (int i = 60; i >= 0; i--) 
    {
        if ((n >> i) & 1) 
        {
            res += nCr[i][k];
            k--;
        }
        if (k < 0) break;
    }
    if (k == 0) res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    precompute();
    while (t--) 
    {
        long long n, k;
        cin >> n >> k;
        long long num = 0;
        for (int bits = 1; bits <= 60; bits++) 
        {
            for (int msb = 0; msb <= 60; msb++) 
            {
                if (bits + msb <= k) 
                {
                    long long high = (1LL << (msb + 1)) - 1;
                    long long low = (1LL << msb);
                    if (low > n) continue;
                    num += countWithSetBits(min(n, high), bits) - countWithSetBits(low - 1, bits);
                }
            }
        }
        cout << n - num << endl;
    }
}
