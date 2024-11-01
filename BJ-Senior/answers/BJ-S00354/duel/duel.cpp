#include <bits/stdc++.h>
using namespace std;


int n,s,r[100007],f[100007];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>r[i];
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(r[i]!=r[i-j] && f[i-j]!=1)
            {
                s++;
                f[i-j]=1;
                break;
            }
        }
    }
    cout<<n-s+1;
    return 0;
}