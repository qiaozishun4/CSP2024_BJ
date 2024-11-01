#include <iostream>
#include <algorithm>
using namespace std;
long long ans[2010][2010];
long long mx, mx2[20010], t, i,j, n, a[20010],tas,mxa;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n>2000)
            break;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            mxa=max(mxa,a[i]);
        }
        tas=0;            
        for(i=1;i<=n;i++)
        {
            ans[i][1]=0;
            for(j=1;j<=i-1;j++)
                {
                    ans[i][1]=max(ans[i][1],ans[i-1][j]+(a[i]==a[i-1-j]?a[i]:0));
                }
            for(j=2;j<=i;j++)
            {
                ans[i][j]=ans[i-1][j-1]+(a[i]==a[i-1]?a[i]:0);
            }
        }
        for(i=1;i<=n;i++)
        {
            tas=max(tas,ans[n][i]);
        }
        cout<<tas<<endl;
    }
    // It sounds so different!
    return 0;
}