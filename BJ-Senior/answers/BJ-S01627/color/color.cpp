#include<bits/stdc++.h>
using namespace std;
int a[200010],c[200010],p[200010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int num=0,h=0;
            for(int j=i-1; j>=1; j--)
            {
                if(a[j]==a[i])
                {
                    h=j;
                    break;
                }
                if(c[j]==1&&p[j]!=0)
                {
                    num+=a[j];
                }
            }
            //cout<<i<<" "<<num<<endl;
            if(num<a[i]&&h!=0)
            {
                //cout<<111<<endl;
                c[h]=1;
                c[i]=1;
                ans+=a[i];
                ans-=num;
                p[i]=h;
                for(int j=i; j>h; j--)
                {
                    if(c[j]==1)
                    {
                        c[j]=0;
                        c[p[j]]=0;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
