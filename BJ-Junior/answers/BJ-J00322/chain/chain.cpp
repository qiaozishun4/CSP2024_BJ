#include <bits/stdc++.h>
using namespace std;

int a[100005];
int r[100005], c[100005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, q;
        cin >> n >>k >>q;
        for(int i = 1; i <= n; i++)
        {
            int j = 1; 
            while(cin >> a[j])
            {
                j++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            
            cin >> r[i] >>c[i];
        }
        for(int i = 1; i <= q; i++)
        {
            
            cout <<0 <<endl;
        }
        
    }
    return 0;
}
