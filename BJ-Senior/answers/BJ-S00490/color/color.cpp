#include<bits/stdc++.h>
using namespace std;
int n,T;
int a[16];
int w[16];
int solve()
{
    int ans=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=i-1;j>=1;--j)
        {
            if (a[i]==a[j])
            {
                if (w[i]==w[j])
                {
                    ans+=w[i];
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ans;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>w[i];
        }
        int maxn=0;
        for (a[1]=0;a[1]<=1;++a[1])
        for (a[2]=0;a[2]<=1;++a[2])
        for (a[3]=0;a[3]<=1;++a[3])
        for (a[4]=0;a[4]<=1;++a[4])
        for (a[5]=0;a[5]<=1;++a[5])
        for (a[6]=0;a[6]<=1;++a[6])
        for (a[7]=0;a[7]<=1;++a[7])
        for (a[8]=0;a[8]<=1;++a[8])
        for (a[9]=0;a[9]<=1;++a[9])
        for (a[10]=0;a[10]<=1;++a[10])
        for (a[11]=0;a[11]<=1;++a[11])
        for (a[12]=0;a[12]<=1;++a[12])
        for (a[13]=0;a[13]<=1;++a[13])
        for (a[14]=0;a[14]<=1;++a[14])
        for (a[15]=0;a[15]<=1;++a[15])
        {
            maxn=max(maxn,solve());
        }
        cout<<maxn<<endl;
    }
    return 0;
}
