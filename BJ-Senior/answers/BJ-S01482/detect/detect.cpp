#include <bits/stdc++.h>
using namespace std;
int T,speed[100010],fw[100010][100010];
int ans,l;
int n,m,L,V;
struct car
{
    int d,v,a;

}x[100010];
void fanwei(int q,int j)
{
    int i=0;
    while(speed[i]>q)
    {
        fw[j][i]++;
        i++;
    }
}
void bl()
{
    int maxx=0,sum=0,o=0;
    while(l!=0)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(fw[j][i]==fw[j+1][i])
                    sum++;
            }
            if(sum>maxx)
                o=i;
            maxx=max(maxx,sum);
            sum=0;
        }
        for(int i=0;i<m;i++)
        {
            if(fw[i][o]==1)
            {
                for(int j=0;j<n;j++)
                    fw[i][j]=0;
                l--;
            }
        }
        ans--;
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    int bt,bs;
    for(int num=0;num<T;num++)
    {

        cin>>n>>m>>L>>V;
        ans=l=m;
        for(int i=0;i<n;i++)
            cin>>x[i].d>>x[i].v>>x[i].a;
        for(int i=0;i<m;i++)
            cin>>speed[i];
        for(int i=0,j=0;i<n;i++)
        {
            bt=(V-x[i].v)/x[i].a;
            bs=x[i].v*bt+0.5*x[i].a*bt*bt;
            fanwei(j,L-bs);
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
