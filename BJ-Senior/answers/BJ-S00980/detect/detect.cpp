#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,l,mv,ans1,ans2;
int d[100050],v[100050],a[100050];
int h[100050];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out",'w',stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>l>>mv;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(d[i]<=p[j]&&v[i]>mv)
                {
                    ans1++;
                    h[j]=j;
                }
            }
        ans2=m-1;
        cout<<ans1<<" "<<ans2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}