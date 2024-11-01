#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int s[100005],att[100005],cnt,ans;
int main()
{

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])cnt++;
        s[cnt]++;
    }
    for(int i=1;i<=cnt;i++)att[i]=s[i];
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            if(s[i]>att[j])s[i]-=att[j],att[j]=0;
            else
            {
                att[j]-=s[i],s[i]=0;
                break;
            }
        }
        ans+=s[i];
    }
    cout<<ans;
    return 0;
}