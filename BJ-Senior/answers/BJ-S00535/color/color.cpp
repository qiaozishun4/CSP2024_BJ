#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100100];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=15)
        {
            ll u=(1<<n),ans=0,wc=0;
            for(int i=0;i<u;i++)
            {
                ll lb=0,lr=0,anss=0;

                for(int j=0;j<n;j++)
                {
                    ll col=i&(1<<j);
              //      cout<<"col"<<col<<" ";
                    if(col!=0)//blue
                    {
                  //      cout<<j+1<<" "<<a[lb]<<" "<<a[j+1]<<endl;
                        if(a[lb]==a[j+1]) anss+=a[j+1];
                        lb=j+1;
                    }
                    else//red
                    {
               //         cout<<j+1<<" "<<a[lr]<<" "<<a[j+1]<<endl;
                        if(a[lr]==a[j+1]) anss+=a[j+1];
                        lr=j+1;
                    }
                }
            //    cout<<endl;
                if(ans<anss) wc=i;
                ans=max(ans,anss);
            }
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
