#include<bits/stdc++.h>
using namespace std;
int ched[100005],chev[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int n,m,L,V,ans=0;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>L>>V;
        int d,v,a,maxn=0;
        for(int j=1;j<=n;j++)
        {
            cin>>d>>v>>a;
            ched[j]=d;
            chev[j]=v;
        }
        int p;
        for(int j=1;j<=m;j++)
        {
            cin>>p;
            maxn=max(maxn,p);
        }
        for(int j=1;j<=n;j++)
        {
            if((chev[j]>V) && (ched[j]<=maxn))
            {
                ans++;
            }
        }
        cout<<ans<<" ";
        if(ans)
        {
            cout<<m-1<<endl;
        }
        else
        {
            cout<<m<<endl;
        }
        ans=0;
    }
    return 0;
}
