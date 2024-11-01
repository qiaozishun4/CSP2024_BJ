#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int T=0,n,m,L,V,d,v,a,p[N]={0},num=0,ans=0;
struct road
{
    double dis=0,d=0;
    bool a;
}s[N];
struct car
{
    int ci,i,j,ge=0;
}con[N];
vector<int> vv[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;

        for(int i=1;i<=n;i++)
        {
            cin>>d>>v>>a;
            if(a>0)
            {
                s[i].a=true;
                if(v>=V) s[i].dis=d;
                else if(v<V) s[i].dis=d+(V*V-v*v)/(2*a);

            }
            else if(a==0)
            {
                s[i].a=true;
                if(v>V) s[i].dis=d;
                else if(v<=V) s[i].dis=-1;
            }
            else if(a<=0)
            {
                s[i].a=false;
                if(v>V)
                {
                    s[i].d=d;
                    s[i].dis=d+(v*v-V*V)/(2*abs(a));
                }
                else if(v<=V)
                {
                    s[i].dis=-1;
                }
            }
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++)
        {
            con[i].ci=i;
            if(s[i].dis!=-1)
            {
                con[i].i=m;
                for(int j=1;j<=m;j++)
                {
                    if(s[i].a==true)
                    {
                        if(p[j]>s[i].dis)
                        {
                            vv[j].push_back(i);
                            con[i].i=min(con[i].i,j);
                            con[i].j=max(con[i].j,j);
                        }
                    }
                    else if(s[i].a==false)
                    {
                        if(p[j]>=s[i].d && p[j]<s[i].dis)
                        {
                            vv[j].push_back(i);
                            con[i].i=min(con[i].i,j);
                            con[i].j=max(con[i].j,j);
                        }
                    }
                }
            }
            if(con[i].i>con[i].j) con[i].i=0;
        }

        for(int i=1;i<=n;i++)
        {
            if(con[i].i!=0 || con[i].j!=0) num++;

            if(con[i].j!=0) con[i].ge=con[i].j-con[i].i+1;
        }
        cout<<num<<" ";
        int ji=0;
        for(int i=1;i<=m;i++)
        {
            if(vv[i].size()>0)
            {
                for(int j=0;j<vv[i].size();j++)
                {
                    if(con[vv[i][j]].ge>1)
                    {
                        ji++;
                    }
                }
                if(ji==vv[i].size())
                {
                    ans++;
                    for(int j=1;j<=vv[i].size();j++)
                    {
                        con[vv[i][j]].ge--;
                    }
                }
                ji=0;
            }
            else if(vv[i].size()==0) ans++;
        }

        cout<<ans<<endl;

        num=0;
        ans=0;
        for(int i=0;i<=m;i++) vv[i].clear();
        for(int i=1;i<=n;i++)
        {
            con[i].ci=0;
            con[i].ge=0;
            con[i].i=0;
            con[i].j=0;
            s[i].a=true;
            s[i].d=0;
            s[i].dis=0;
        }
    }


    return 0;
}
