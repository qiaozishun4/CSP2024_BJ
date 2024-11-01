#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
bool ss[N];
int check()
{
    int red=0,blue=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ss[i])
        {
            if(a[i]==a[red])
            {
                cnt+=a[i];
            }
            red=i;
        }
        else
        {
            if(a[i]==a[blue])
            {
                cnt+=a[i];
            }
            blue=i;
        }
    }
    return cnt;
}
void A(int x)
{
    if(x>n)
    {
        ans=max(ans,check());
        return;
    }
    A(x+1);
    ss[x]=1;
    A(x+1);
    ss[x]=0;
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        A(1);
        cout<<ans<<endl;
    }
    return 0;
}