#include<bits/stdc++.h>
using namespace std;
const int N=100001;
bool p[3001][3001];
struct Row{
    int id,key;
} f[N];
bool cmp(Row x,Row y)
{
    return x.key>y.key;
}
bool cd[N];
bool up[N];
int n,m,idx;
int V,T,L;
int v[N],d[N],a[N];
int loc[N];
void Trans(int l,int r)
{
    ++idx;
    for (int i=l;i<=r;++i)
    {
        p[idx][i]=1;
    }
    return ;
}
void Merge(int row)
{
    for (int i=1;i<=idx;++i)
    {
        if (p[i][row] || cd[i])
        {
            cd[i]=1;
        }
    }
    return ;
}
bool check()
{
    bool flag=true;
    for (int i=1;i<=idx;++i)
    {
        if (!cd[i])
        {
            flag=false;
            break;
        }
    }
    return flag;
}
void Mems()
{
    V=0;
    L=0;
    n=m=0;
    idx=0;
    memset(v,0,sizeof(v));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(f,0,sizeof(f));
    memset(cd,0,sizeof(cd));
    memset(up,0,sizeof(up));
    for (int i=1;i<=m;++i)
    {
        f[i].id=i;
    }
    return ;
}
int Find(double k)
{
    int l=1,r=m;
    if ((double)k>(double)loc[m])
    {
        return -1;
    }
    while (l<r)
    {
        int mid=(l+r)>>1;
        if ((double)k<=(double)loc[mid])
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int cnt=0;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        Mems();
        cin>>n>>m>>L>>V;
        for (int i=1;i<=n;++i)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for (int i=1;i<=m;++i)
        {
            cin>>loc[i];
        }
        for (int i=1;i<=n;++i)
        {
            //cout<<i<<endl;
            double dis=0;
            if (a[i]<=0)
            {
                int fst=Find((double)d[i]);
                //cout<<"fst:"<<fst<<endl;
                if (fst==-1)
                {
                    continue;
                }
                else
                {
                    double val=sqrt(2*a[i]*(loc[fst]-d[i])+v[i]*v[i]);
                    if ((double)val>(double)V)
                    {
                        ++cnt;
                        int fnl=0;
                        if (!a[i])
                        {
                            fnl=-1;
                        }
                        else
                        {
                            double dis_1=(double)d[i]+(V*V-v[i]*v[i])/(2.0*a[i]);
                            double tim=v[i]*1.0/a[i];
                            double dis_2=(double)d[i]+a[i]*tim*tim/2.0;
                            dis=max(dis_1,dis_2);
                            fnl=Find(dis);
                        }
                        if (fnl==-1)
                        {
                            Trans(fst,m);
                        }
                        else
                        {
                            Trans(fst,fnl-1);
                        }
                        up[i]=true;
                        //cout<<i<<" chaosu"<<endl;
                        continue;
                    }
                }
            }
            else
            {
                int fst=Find((double)d[i]);
                //cout<<"fst:"<<fst<<endl;
                if (fst==-1)
                {
                    continue;
                }
                else
                {
                    double val=sqrt(2*a[i]*(loc[fst]-d[i])+v[i]*v[i]);
                    if ((double)val>(double)V)
                    {
                        ++cnt;
                        Trans(fst,m);
                        up[i]=true;
                        //cout<<i<<" chaosu"<<endl;
                        continue;
                    }
                    else
                    {
                        dis=(double)d[i]+(V*V-v[i]*v[i])/(2.0*a[i]);
                        int lst=Find(dis+0.001);
                        //cout<<dis<<" "<<lst<<endl;
                        if (Find(dis)!=-1)
                        {
                            ++cnt;
                            Trans(lst,m);
                            up[i]=true;
                            continue;
                        }
                    }
                }
            }
        }
        cout<<cnt<<" ";
        for (int i=1;i<=m;++i)
        {
            for (int j=1;j<=idx;++j)
            {
                if (p[i][j])
                {
                    f[j].key++;
                }
            }
        }
        sort(f+1,f+m+1,cmp);
        for (int i=1;i<=m;++i)
        {
            Merge(i);
            if (check())
            {
                cout<<m-i<<endl;
                break;
            }
        }
    }
    return 0;
}
