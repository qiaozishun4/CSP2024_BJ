#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005];
int st(int a[])
{
    int maxn = -1;
    int t;
    for(int i = 1; i <= w; i++)
    {
        if(maxn <= a[i])
        {
            maxn = a[i];
            t = i;
        }

    }
    a[t] = -1;

    return maxn;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    while(T)
    {
        cin >> n ;
        for(int i = 1; i <= n; i++)
        {
            cin >>a[i];
        }
        for(long long i = 1; i <= w; i++)
        {
            b[i] = st(a);
        }
        cout << b[1] << endl;
    }
    return 0;
}