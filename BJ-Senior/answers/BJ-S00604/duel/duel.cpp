#include <bits/stdc++.h>
using namespace std;
int n,a[100005],p,ans,q;
bool flag[100005];
int main()
{
	freopen ("duel.in","r",stdin);
	freopen ("duel.out","w",stdout);
    cin>>n;
    ans=n;
    q=1;
    p=2;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort (a+1,a+n+1);
    while (a[p]==a[q]&&p!=n+1)
    {
        p++;
    }
    if (p==n+1)
    {
        cout<<n<<endl;
        return 0;
    }
    while (p<=n)
    {
        if (a[p]>a[q])
        {
            ans--;
            q++;
            p++;
        }
        else
        {
            while (a[p]<=a[q]&&p!=n+1)
            {
                p++;
            }
            if (p==n+1)
            {
                break;
            }
            else
            {
                ans--;
                q++;
                p++;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
