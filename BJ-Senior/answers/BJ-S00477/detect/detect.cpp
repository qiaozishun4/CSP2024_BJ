#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct Node
{
    int d,v,a;//距离，初速，加速
}car[maxn];
int p[maxn];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(car,0,sizeof(car));
        memset(p,0,sizeof(p));
        int n,m,L,V,maxp=0,t=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;

        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            maxp=max(maxp,p[i]);
        }
        for(int i=1;i<=n;i++)
        {

            if(car[i].a==0&&car[i].v>V&&car[i].d<=maxp)t++;
            else if(car[i].a>0&&car[i].v==V&&car[i].d<maxp)t++;
            else if(car[i].a>0&&double((V*V-car[i].v*car[i].v)/(2*car[i].a))+car[i].d<maxp)t++;
        }
        if(t!=0)cout<<t<<" "<<m-1<<endl;
        else cout<<t<<" "<<m<<endl;
    }
    return 0;
}
