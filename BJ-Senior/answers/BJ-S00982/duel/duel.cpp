#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int num=0;
    int a[n+1],b[n+1];
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int o=0;
        for(int j=i;j<=n;j++)
        {
            if(a[i]<a[j] && b[j]==0)
            {
                num++;
                b[j]=1;
                o=1;
            }
            if(o==1) break;
        }
    }
    cout<<n-num<<endl;
    return 0;
}
