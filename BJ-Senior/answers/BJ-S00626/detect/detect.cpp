#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int d[N],v[N],a[N];
int p[N];
bitset<N>cam,car;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int n,m,L,V;
    while(t--)
    {
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        cam=0;
        bool f=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            cam[i]=1;
        }
        double pos;
        int tmp,tmp2,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>p[m])
            {
                continue;
            }
            car=0;
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    cnt++;
                }
            }
            if(a[i]>0)
            {
                pos=d[i]+((V*V-v[i]*v[i])/(2*a[i]));
                if((int)pos>=p[m])
                {
                    continue;
                }
                cnt++;
                tmp=upper_bound(p+1,p+1+m,(int)pos)-p;
                for(int j=tmp;j<=m;j++)
                {
                    car[j]=1;
                }
                if((cam&car)==0)
                {
                    cam|=car;
                }
                else
                {
                    cam&=car;
                }
            }
            if(a[i]<0)
            {
                f=0;
                if(v[i]<=V)
                {
                    continue;
                }
                pos=d[i]+((V*V-v[i]*v[i])/(2*a[i]));
                tmp=upper_bound(p+1,p+1+m,d[i])-p-1;
                if((int)pos>=p[m])
                {
                    tmp2=m+1;
                }
                else
                {
                    tmp2=upper_bound(p+1,p+1+m,(int)pos)-p;
                }
                if(d[i]>p[tmp]&&pos<(double)p[tmp+1])
                {
                    continue;
                }
                cnt++;
                for(int j=tmp+1;j<tmp2;j++)
                {
                    car[j]=1;
                }
                if((cam&car)==0)
                {
                    cam|=car;
                }
                else
                {
                    cam&=car;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(cam[i]==0)
            {
                ans++;
            }
        }
        if(f==1)
        {
            ans=m-1;
        }
        cout<<cnt<<' '<<ans<<endl;
    }
    return 0;
}