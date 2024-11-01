#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,T,ans;
struct node
{
    double v,a,d;
    double vstart,vend;//chaosujuli
    bool vis;//huibuhuichaosu
}car[200001];
struct student
{
    int s;
    bool st;
}cv[200001];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        cin>>n>>m>>L>>V;
        ans=0;
        memset(car,0,sizeof(car));
        memset(cv,0,sizeof(cv));
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;
            car[i].vstart=car[i].d;
            car[i].vend=L;
            if(car[i].a==0)
            {
                if(car[i].v<=V) car[i].vis=false;
                else car[i].vis=true;
            }
            else if(car[i].a>0)
            {
                if(car[i].v<=V)
                {
                    car[i].vstart=(V*V-car[i].v*car[i].v)/2/car[i].a+car[i].d;
                }
                if(car[i].vstart<L) car[i].vis=true;
                else car[i].vis=false;
            }
            else
            {
                if(car[i].v>V)
                {
                    car[i].vend=(V*V-car[i].v*car[i].v)/2/car[i].a+car[i].d;
                    car[i].vis=true;
                }
                else car[i].vis=false;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>cv[i].s;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(car[i].vis==true)
                {
                    if(car[i].a>0&&cv[j].s>car[i].vstart)
                    {
                        ans++;
                        break;

                    }
                    else if(car[i].a<0&&cv[j].s>=car[i].vstart&&cv[j].s<car[i].vend)
                    {
                        ans++;
                        break;
                    }
                    else if(car[i].a==0)
                    {
                        ans++;
                        break;
                    }
                }

            }
        }
        
        cout<<ans<<" "<<ans<<endl;
    }
    return 0;
}
