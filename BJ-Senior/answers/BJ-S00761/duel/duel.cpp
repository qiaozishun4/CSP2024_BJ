#include<bits/stdc++.h>
using namespace std;
int n,ans=0,maxn=-1,minn=1e9,a[100010],b[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        maxn=max(maxn,x);
        minn=min(minn,x);
        a[x]++,b[x]++;
    }
    for(int i=maxn;i>=minn+1;i--)
    {
        ans+=a[i];
        if(b[i]!=0)
        {
            int t,mao=b[i];
            bool fla=false;
            for(int j=i-1;j>=minn;j--)
            {
                if(a[j]>0)
                {
                    t=j;
                    break;
                }
                if(j==minn&&a[j]==0)fla=true;
            }
            if(fla)continue;
            if(a[t]>=mao)a[t]-=mao,mao=0;
            else mao-=a[t],a[t]=0;
            while(mao!=0)
            {
                int tmp=t;
                if(tmp==minn)break;
                for(int j=tmp-1;j>=minn;j--)
                {
                    if(a[j]>0)
                    {
                        t=j;
                        break;
                    }
                    if(j==minn&&a[j]==0)fla=true;
                }
                if(fla)break;
                if(a[t]>=mao)a[t]-=mao,mao=0;
                else mao-=a[t],a[t]=0;
            }
        }
    }
    ans+=a[minn];
    cout<<ans<<endl;
    return 0;
}
