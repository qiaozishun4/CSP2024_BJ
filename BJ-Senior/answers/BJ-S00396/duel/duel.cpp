#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int i,j,n,m,k,x,y,s=0,l,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>a[l])
        {
            l++;
        }
    }
    cout<<n-l+1<<"\n";
    return 0;
}