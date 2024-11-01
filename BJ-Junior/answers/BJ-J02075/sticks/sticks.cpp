#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],c,bnum[10]={6,2,5,5,4,5,6,3,7,6},ans,number;
void minum(int sc,int cnt)
{
    if(sc==0)
    {
        for(int i=1;i<=cnt;i++)
        {
            number*=10;
            number+=a[i];
        }
        number/=10;
        ans=min(number,ans);
        number=0;
        return ;
    }
    if(sc==1) return ;
    for(int i=0;i<=9;i++)
    {
        if(cnt==1&&i==0) continue;
        if(bnum[i]<=sc)
        {
            a[cnt]=i;
            minum(sc-bnum[i],cnt+1);
        }
    }
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=2147483645;
        cin>>n;
        minum(n,1);
        if(ans>=2147483645) cout<<-1;
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}
