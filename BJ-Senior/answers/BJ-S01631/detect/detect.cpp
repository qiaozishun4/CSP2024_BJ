#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,s,ans=0,q=0;
        int d[100005],v[100005],a[100005],p[100005];
        cin>>n>>m>>l>>s;
        for(int i=1;i<=n;i++)
        {   
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0) q=1;
        }
        if(q=0)
        {
            int max_=-1;
            for(int i=1;i<=m;i++)
            {
                cin>>p[i];
                if(p[i]>max_)
                {
                    max_=p[i];
                }   
            }
            for(int i=1;i<=n;i++)
            {
                if(v[i]>s&&d[i]<=max_)
                {   
                    ans++;
                }
            }
            cout<<ans<<" "<<m-1<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {   
                cin>>d[i]>>v[i]>>a[i];
            }
            int max_=-1;
            for(int i=1;i<=m;i++)
            {
                cin>>p[i];
                if(p[i]>max_)
                {
                    max_=p[i];
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(sqrt(v[i]*v[i]+2*a[i]*(max_-d[i]))>s)
                {
                    ans++;
                }
            }
            cout<<ans<<" "<<m-1<<endl;
        }
    }
    return 0;
}
