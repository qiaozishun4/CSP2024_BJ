#include<bits/stdc++.h>
using namespace std;

long long T;
long long n,m,L,V;
struct
{
    int d,v,a;
}car[100010];
long long p[100010];
double chaosu[100010];
long long chsucnt=0;
long long ans[100010];
long long sum=0;

void work1()
{
    cout<<ans[p[m]]+sum<<" ";
}

void work2()
{
    cout<<m-sum+1<<endl;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=L;i++)
        {
            ans[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;
            double temp=(double((V*V)-(car[i].d*car[i].d)))/(2.0*car[i].a);
            long long t=floor(temp);
            if(car[i].v>=V && car[i].a>=0) for(int j=car[i].d;j<=L;j++) ans[j]++;
            else if(car[i].v>=V && car[i].a<0) for(int j=car[i].d;j<=min(L,t);j++)
            {
                ans[j]++;
                sum++;
            }
            else if(car[i].v<=V && car[i].a>0) for(int j=ceil(temp);j<=L;j++) ans[j]++;
            else continue ;
            if(temp>=0)
            {
                chsucnt++;
                chaosu[chsucnt]=temp;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        work1();
        work2();
    }
    return 0;
}
