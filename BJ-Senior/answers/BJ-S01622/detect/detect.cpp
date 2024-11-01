#include <iostream>
#include <cmath>
using namespace std;
const int N=100005;
int t,n,m,L,V,d[N],a[N],v[N],s,p[N],maxp,ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        cin>>n>>m>>L>>V;
        for(int j=0;j<n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];

        }
        for(int j=0;j<m;j++)
        {
            cin>>p[j];
            maxp=max(maxp,p[j]);
        }
        for(int j=0;j<=n;j++)
        {
            if(a[j]==0)
            {
                s=v[j];
            }
            else
            {
                s=(pow(V,2)-pow(v[j],2))/(2*a[j]);
            }
            if(a[j]>0)
            {
                if(maxp>s)
                {
                    ans++;
                    break;
                }
            }
            else
            {
                for(int q=0;q<m;q++)
                    if(p[q]<s)
                    {
                        ans++;
                        break;
                    }
            }
        }
        cout<<ans<<" "<<0<<endl;
    }
    return 0;
}