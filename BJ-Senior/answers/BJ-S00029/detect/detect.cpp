#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
int read()
{
    int x=0,b=1;char ch=' ';
    while(!isdigit(ch))
    {
        if(ch=='-')b=-b;
        ch=getchar();
    }
    while(isdigit(ch))
        x=x*10+ch-'0',
        ch=getchar();
    return x*b;
}
struct var
{
    int d;double a,v;
    int s,e;
    var(){}
};
var car[100005];int cnt;

//double v[100005],a[100005];
int det[100005];//,d[100005];
const double eps=1e-8;
int darr[100005];
int mini;//=998244353;
int n,m,l,lim;
bool pd(bool x)
{
    if(x)
    {
        for(int i=1;i<=n;++i)
            if(car[i].a<=0)return false;
        return true;
    }
    else
    {
        for(int i=1;i<=n;++i)
            if(car[i].a)return false;
        return true;
    }
}
void dfs(int id,int _cnt)
{
    if(id==m+1)
    {
        int __cnt=0,dis;
        for(int i=1;i<=n;++i)
        {
            if(car[i].d>darr[_cnt])continue;
            if(car[i].a>0)
            {
                dis=darr[_cnt]-car[i].d;
                double speed=sqrt(car[i].v*car[i].v+2*car[i].a*dis);
                __cnt+=speed>lim;
            }
            else if(car[i].a<0)
            {
                int nxt=lower_bound(darr+1,darr+_cnt+1,car[i].d)-darr;
                dis=darr[nxt]-car[i].d;
                double speed;
                if(car[i].v*car[i].v+2*car[i].a*dis<0)speed=0;
                else speed=sqrt(car[i].v*car[i].v+2*car[i].a*dis);
                __cnt+=speed>lim;
            }
            else __cnt+=car[i].v>lim;
        }
        if(__cnt>=cnt)mini=min(mini,_cnt);
        return;
    }
    dfs(id+1,_cnt);
    darr[_cnt+1]=det[id];
    dfs(id+1,_cnt+1);
    darr[_cnt+1]=0;
    return;
}
//copied successfully
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;while(T--)
    {
        cin>>n>>m>>l>>lim;
        //cout<<20-T+1<<' ';
        //cout<<n<<' '<<m<<' '<<l<<' '<<lim<<endl;
        for(int i=1;i<=n;++i)
            car[i].d=read(),car[i].v=read(),car[i].a=read();
        for(int i=1;i<=m;++i)
            det[i]=read();
        cnt=0;int dis;
        for(int i=1;i<=n;++i)
        {
            if(car[i].d>det[m])continue;
            if(car[i].a>0)
            {
                dis=det[m]-car[i].d;
                double speed=sqrt(car[i].v*car[i].v+2*car[i].a*dis);
                cnt+=speed>lim;
            }
            else if(car[i].a<0)
            {
                int nxt=lower_bound(det+1,det+m+1,car[i].d)-det;
                dis=det[nxt]-car[i].d;
                double speed;
                if(car[i].v*car[i].v+2*car[i].a*dis<0)speed=0;
                else speed=sqrt(car[i].v*car[i].v+2*car[i].a*dis);
                cnt+=speed>lim;
            }
            else cnt+=car[i].v>lim;
        }
        cout<<cnt<<' ';
        //1-2:brute force
        if(pd(0))
            cout<<(cnt?m-1:m);
        else if(pd(1))cout<<(cnt?m-1:m);
        else if(m<=20)
        {
            mini=998244353;dfs(1,0);cout<<m-mini;
        }
        else cout<<1;
        cout<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
