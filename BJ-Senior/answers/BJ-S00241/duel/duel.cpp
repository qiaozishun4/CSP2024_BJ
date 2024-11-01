#include<bits/stdc++.h>
using namespace std;
int n,c,d;
int a[10005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int k=1;k<=n;i++)
    {
        cin>>a[k];
    }
    for(int i=1;i<=n;i++)
    {
        int b=10005;
        for(int j=i;j<=n;j++)
        {
            if(a[j]<b)
            b=j;
        }
        c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
    for(int l=1;l<=n;l++)
    {
        for(int m=1,m<=n;m++)
        {
            if((a[m]>a[n])&&(a[m]!=0))
            {
                a[n]==-1;
                a[m]==0;
            }
        }
    }
    for(int o=1;o<=n;o++)
    {
        if(a[o]!=-1)
        {
            d++;
        }
    }
    cout<<d;
    return 0;
}
