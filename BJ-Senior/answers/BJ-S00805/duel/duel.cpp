#include <bits/stdc++.h>
using namespace std;
bool f[100005];
long long r[100005];
long long n;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort (r+1,r+1+n);
    memset(f,1,sizeof(f));
    int minn=r[1],smin=1;
    int num=1;
    for(int i=2;i<=n;i++)
    {
        if (r[i]==minn)
        {
            num++;
            continue;
        }
        else
        {
            for (int j=smin;j<=smin+num;j++)
            {
                if (num+j>n)
                {
                    break;
                }
                else
                {
                    f[num+j]=1;
                    f[j]=0;
                }
            }
            minn=r[i];
            smin=i;
            num=1;
        }
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        if (f[i]==1)
        {
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
