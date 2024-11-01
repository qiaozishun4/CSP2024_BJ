#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int b[100005];
int c[100005];
int ans[100005];
int query(int id,int deep)
{
    return id-(id&((1<<deep)-1))+(1<<deep)+1;
}
int maxx;
vector<int>v[21];
int T;
int id[21];
pair<int,int> anss[25];
int startt=0;
vector<pair<int,pair<int,int> > >change[21];
int calc(int x)
{
    int tt=log2(x);
    if((1<<tt)==x)
    {
        return tt;
    }
    return tt+1;
}
void reset(int deep)
{
    for(int i=0;i<change[deep].size();i++)
    {
        anss[change[deep][i].first]=change[deep][i].second;
    }
    change[deep].clear();
}
bool flag=0;
void add(int deep,int x,int idd)
{
    //cout<<"::"<<deep<<" "<<x<<" "<<idd<<endl;
    if(id[deep]==0)
    {
        id[deep]=idd;
        reset(deep);
        if(v[deep][x/2]==0&&a[idd]>=deep)
        {
            maxx=max(maxx,query(idd,deep));
            if(anss[a[idd]].first==-1)
            {
                startt=idd;
            }
            else
            {
                startt=anss[a[idd]].second;
            }
            //cout<<"!!"<<startt<<endl;
            return;
        }
        if(v[deep][x/2]==0)
        {
            return;
        }
        if(startt!=0)
        {
            return;
        }
        if(v[deep][x/2]==1)
        {
            if(a[idd]>20||(anss[a[idd]].first<=20&&(anss[a[idd]].first==-1||anss[anss[a[idd]].first].first==-1)))
            {
                for(int i=0;i<deep;i++)
                {
                    change[deep].push_back(make_pair(i,anss[i]));
                    anss[i]=make_pair(a[idd],idd);
                }
            }
            else
            {
                for(int i=0;i<deep;i++)
                {
                    change[deep].push_back(make_pair(i,anss[i]));
                    anss[i]=anss[a[idd]];
                }
            }
            /*for(int i=0;i<=20;i++)
            {
                cout<<anss[i].first<<" ";
            }
            cout<<endl;*/
        }
    }
    else
    {
        reset(deep);
        if((v[deep][x/2]==0&&a[id[deep]]>=deep)||(v[deep][x/2]==1&&a[idd]<deep))
        {
            //cout<<v[deep][x/2]<<endl;
            idd=id[deep];
        }
        id[deep]=0;
        add(deep+1,x/2,idd);
        if(v[deep][(x+1)/2]==0)
        {
            if(anss[0].first==-1)
            {
                for(int i=0;i<deep;i++)
                {
                    change[deep].push_back(make_pair(i,anss[i]));
                    anss[i]=make_pair(0,0);
                }
            }
            else
            {
                for(int i=0;i<deep;i++)
                {
                    change[deep].push_back(make_pair(i,anss[i]));
                    anss[i]=anss[0];
                }
            }
        }
        /*for(int i=0;i<=20;i++)
        {
            cout<<anss[i].first<<" ";
        }
        cout<<endl;*/
    }
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int N=calc(n);
    for(int i=1;i<=N;i++)
    {
        char x;
        for(int j=0;j<(1<<(N-i));j++)
        {
            cin>>x;
            v[i].push_back(x-'0');
        }
    }
    cin>>T;
    while(T--)
    {
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
        {
            a[i]^=x[i%4];
            //cout<<a[i]<<" ";
        }
        //cout<<endl;
        memset(id,0,sizeof(id));
        for(int i=0;i<=20;i++)
        {
            change[i].clear();
            anss[i]=make_pair(-1,0);
        }
        maxx=0;
        for(int i=1;i<=n;i++)
        {
            if(calc(i)==i)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            if(i>=maxx)
            {
                startt=0;
                maxx=i+1;
            }
            add(1,i-1,i);
            if(startt!=0)
            {
                ans[i]=((1<<(calc(i)))+maxx)*((1<<(calc(i)))-maxx+1)/2+startt;
                //cout<<"$$"<<startt<<endl;
            }
            else
            {
                ans[i]=((1<<(calc(i)))+maxx)*((1<<(calc(i)))-maxx+1)/2+anss[0].second;
                //cout<<"$$"<<anss[0].second<<endl;
            }
            //cout<<"!!"<<i<<" "<<anss[0].second<<endl;
            //cout<<"*****"<<maxx<<" "<<(1<<(calc(i)))<<endl;
            /*for(int i=0;i<=21;i++)
            {
                cout<<anss[i].second<<" ";
            }
            cout<<endl;*/
        }
        int ansss=0;
        /*for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;*/
        for(int i=1;i<=m;i++)
        {
            ansss^=(i*ans[c[i]]);
        }
        cout<<ansss<<endl;
    }
    return 0;
}
