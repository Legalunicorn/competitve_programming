#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int op_ct = 0;

        for (int i = 1; i < n - 1; i += 2)
        {
            if (a[i] == a[i - 1] || a[i] == a[i + 1] || a[i] == 7 - a[i + 1] || a[i] == 7 - a[i - 1])
                op_ct++;
        }
        
        if (n % 2 == 0)
        {
            if (a[n - 1] == a[n - 2] || a[n - 1] == 7 - a[n - 2])
                op_ct++;
        }

        cout << op_ct << endl;
    }
    
}
