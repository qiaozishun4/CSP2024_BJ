#include <bits/stdc++.h>
using namespace std;
int t,n,a[200001],color[200001];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while (t--)
    {
        int maxx=0;
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=0;i<pow(2,n);i++)
        {
            memset(color,sizeof(color),0);
            int cnt=0,x=i,sum=0;
            while (x>0)
            {
                color[++cnt]=x%2;
                x/=2;
            }
            for (int k=2;k<=n;k++)
                for (int j=k-1;j>=1;j--)
                    if (color[k]==color[j])
                    {
                        if (a[k]==a[j])
                            sum+=a[k];
                        break;
                    }
            maxx=max(maxx,sum);
        }
        cout<<maxx<<endl;
    }
}