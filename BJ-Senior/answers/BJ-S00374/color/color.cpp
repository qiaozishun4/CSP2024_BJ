#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color","r",stdin);
    freopen("color","w",stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        int n;
        cin >> n;
        int A[n+5];
        for(int j = 1;j <= n;j++)
        {
            cin >> A[j];
        }
        sort(A+1, A+n+1);
        int sum = 0;
        for(int j = 2;j <= n;j++)
        {
            if(A[j] == A[j-1])
            {
                sum += A[j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}