#include<bits/stdc++.h>
using namespace std;
int a[100015],b[100015];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[j] > a[i])
            {
                a[i] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != 0)
            cout << a[i] << " " <<endl;
    }
    return 0;
}
