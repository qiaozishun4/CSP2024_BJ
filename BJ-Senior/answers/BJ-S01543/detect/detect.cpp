#include<bits/stdc++.h>
using namespace std;
int g[100000];
int v[100000];
int a[100000];
int c[100000];
double sug[100000];
int ans[1000000];
int cut[1000000];
bool h[100000]={1};
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,u,z;
        cin>>x>>y>>u>>z;
        for(int j=1;j<=x;j++)
        {
            cin>>g[j]>>v[j]>>a[j];
        }

        for(int j=1;j<=x;j++)
        {
            if(g[j]!=0)
            {
               sug[j]=(z*z-v[j]*v[j])/(2*a[j])+g[j];
            }
            else{
                sug[j]=0;
            }
        }
        for(int j=1;j<=y;j++)
        {
            cin>>c[j];
        }
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=y;k++)
            {
                if(sug[j]!=0&&sug[j]<c[k]&&sug[j]>c[k-1]&&sug[j]<z)
                {
                   h[k]=0;
                   ans[i]++;
                }
            }
        }
        for(int j=1;j<=y;j++)
        {
            if(h[j]==1)
            {
                cut[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<cut[i]<<ans[i]<<endl;
    }
    return 0;
}
