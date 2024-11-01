#include<bits/stdc++.h>
using namespace std;
int n,l,m,V,d[100005],v[100005],p[100005],ans;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,t;
    cin>>T;
    for(int K=1;K<=T;K++)
    {
        ans=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>t;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(p[m]>=d[i]&&v[i]>V) ans++;
        }
        if(ans==0)
        {
            cout<<ans<<" "<<m<<endl;
        }
        else
        {
            cout<<ans<<" "<<m-1<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}