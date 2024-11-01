#include<bits/stdc++.h>
using namespace std;
int n,a[100010],r[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        r[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        if(a[i+1]!=a[i])
        {
            r[a[i+1]]=max(r[a[i+1]],r[a[i]]);
            r[a[i]]=0;
        }
    }
    cout<<r[a[n]]<<endl;
    return 0;
}
