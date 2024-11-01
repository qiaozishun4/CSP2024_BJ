#include <bits/stdc++.h>
using namespace std;
long long T;
long long a[200005];
bool color[200005],fl[200005];//0 blue,1 red
long long n;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    int f=1;
    color[1]=0;
    for (int i=1;i<=T;i++)
    {
        int ans=0;
        memset(a,0,sizeof(a));
        memset(fl,0,sizeof(fl));
        cin>>n;
        for (int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        for (int j=1;j<=n;j++)
        {
            for (int k=j+1;k<=n;k++)
            {
                if (a[j]==a[k] && fl[j]==0 && fl[k]==0)
                {
                    if (f==1)
                    {
                        color[j]=1;
                        color[k]=1;
                    }
                    fl[j]=1;
                    fl[k]=1;
                    f*=-1;
                    ans+=a[k];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
