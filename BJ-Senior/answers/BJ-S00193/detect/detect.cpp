#include <bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
int t;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
            cin>>p[i];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0 && v[i]<=V)
            {
                continue;
            }
            int b;
            if(a[i]==0)
                b=d[i];
            else{
                if(v[i]>V)
                    b=d[i];
                else
                {
                    int sss;
                    double ss=(V*V-v[i]*v[i])*1.0/(2*a[i]);
                    if(int(ss)==ss)
                        sss=ss+1;
                    else
                        sss=int(ss)+1;
                    b=sss+d[i];
                }
            }
            if(b<=p[m])
            {
                    ans++;

            }
        }
        if(ans==0)
            m++;
        cout<<ans<<" "<<m-1<<endl;
    }
    return 0;
}

