#include<bits/stdc++.h>
using namespace std;
int p[100010],bg[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,L,V,line=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            int d,v,a;
            cin>>d>>v>>a;
            if(a==0&&v>V)bg[i]=d;
            else if(a==0)bg[i]=1e9;
            else{
                double dis=1.0*(V*V-v*v)/(2*a);
                if(dis<0)bg[i]=d;
                else if(d+dis==(int)(d+dis))bg[i]=d+dis+1;
                else bg[i]=(int)ceil(d+dis);
            }
        }
        sort(bg+1,bg+n+1);
        bool flag=0;
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=n;i>=1;i--)
        {
            if(bg[i]<=p[m])
            {
                cout<<i<<" "<<m-1<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)cout<<0<<" "<<m<<endl;
    }
    return 0;
}