#include <bits/stdc++.h>
using namespace std;
long long c[200005]={};
bool b[200005];
long long ans=0;
void getsum(int n)
{
    long long sum=0;
    for(int i=n;i>=2;i--)
    {
        long long lastsame=0;
        for(int j=i-1;j>=1;j--)
        {
            if(b[i]==b[j])
            {
                if(c[i]==c[j])
                {
                    lastsame=c[i];
                    break;
                }
            }
        }
        sum+=lastsame;
    }
    if(sum>ans)
        ans=sum;
}
void color(int s,int n)
{
    b[s]=0;
    if(s==1)
        getsum(n);
    else
        color(s-1,n);
    b[s]=1;
    if(s==1)
        getsum(n);
    else
        color(s-1,n);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> c[i];
        }
        color(n,n);
        cout<<ans<<endl;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            c[i]=0;
        }
    }
    return 0;
}
