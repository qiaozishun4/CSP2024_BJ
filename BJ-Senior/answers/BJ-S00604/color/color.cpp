#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],t,ans=LONG_MIN,r[200005];
void dfs (int x)
{
    if (x>n)
    {
        int c[200005]={},rd,be,se=0;
        if (!r[1])
        {
            rd=1;
            be=0;
        }
        else
        {
            rd=0;
            be=1;
        }
        for (int i=2;i<=n;i++)
        {
            if (r[i]&&be)
            {
                if (a[i]==a[be])
                {
                    c[i]=a[i];
                }
                else
                {
                    c[i]=0;
                }
            }
            if (!r[i]&&rd)
            {
                if (a[i]==a[rd])
                {
                    c[i]=a[i];
                }
                else
                {
                    c[i]=0;
                }
            }
            if (r[i])
            {
                be=i;
            }
            else
            {
                rd=i;
            }
        }
        for (int i=1;i<=n;i++)
        {
            se+=c[i];
        }
        ans=max (ans,se);
        return;
    }
    r[x]=0;
    dfs (x+1);
    r[x]=1;
    dfs (x+1);
}
signed main()
{
	freopen ("color.in","r",stdin);
	freopen ("color.out","w",stdout);
	cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs (1);
        cout<<ans<<endl;
        ans=LONG_MIN;
    }
	return 0;
}
