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
        int n,m,l,V,d[100005],v[100005],a[100005],p[100005];
        ci>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    sum++;
                }
            }
        }
        cout<<sum<<" "<<m-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
