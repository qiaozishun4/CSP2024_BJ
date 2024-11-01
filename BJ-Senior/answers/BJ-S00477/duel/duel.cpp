#include<bits/stdc++.h>
using namespace std;
int t[100005],f=-1;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x,maxr=0,minr=100005,sh=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        maxr=max(maxr,x);
        minr=min(minr,x);
        t[x]++;
    }
    //for(int i=minr;i<=maxr;i++)if(t[i]!=0)cout<<t[i]<<" ";
    for(int i=minr;i<=maxr;i++)
    {
        if(t[i]!=0)
        {
            if(f==-1)f=i;
            else
            {
                if(t[i]>=t[f])
                {

                    if(sh>0)
                    {

                        if(t[i]-t[f]>=sh)sh=0;
                        else sh-=(t[i]-t[f]);
                    }
                }
                else
                {
                    t[f]-=t[i];
                    sh+=t[f];
                }
                f=i;
            }
        }

    }
    cout<<t[maxr]+sh;
    return 0;
}
