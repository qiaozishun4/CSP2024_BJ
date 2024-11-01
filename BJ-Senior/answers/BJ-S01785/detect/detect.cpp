#include<bits/stdc++.h>
using namespace std;
int s[100010],v[100010],w[100010];
int p[10010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,ans=0;
    cin>>t;
    while(t--)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i]>>v[i]>>w[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]>V&&s[i]<=p[m])
            {
                ans++;
            }
        }
        cout<<ans<<" "<<ans-1<<endl;
    }
    return 0;
}
