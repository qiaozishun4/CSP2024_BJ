#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
struct node{
    int l,r;
    bool operator<(const node &rhs)
    {
        if(r<rhs.r)
        {
            return true;
        }
        return false;
    }
}t[100005];
int cnt;
double ll[100005],rr[100005];
const double eps=1e-10;
void solve(double x0,double v0,double a,int i)
{
    if(v0>V)
    {
        if(a>=0)
        {
            ll[i]=x0;
            rr[i]=L;
        }
        else
        {
            ll[i]=x0;
            rr[i]=x0+(1.0*V*V-v0*v0)/2.0/a-eps;
        }
    }
    else
    {
        if(a<=0)
        {
            ll[i]=1;
            rr[i]=-1;
        }
        else
        {
            ll[i]=x0+(1.0*V*V-v0*v0)/2.0/a+eps;
            rr[i]=L;
        }
    }
}
map<double,int>s;
void add(double l,double r)
{
    map<double,int>::iterator itl=s.lower_bound(l);
    if(itl==s.end())
    {
        return;
    }
    map<double,int>::iterator itr=s.upper_bound(r);
    if(itr==s.begin())
    {
        return;
    }
    itr--;
    //cout<<"!!"<<(*itl).second<<" "<<(*itr).second<<endl;
    if((*itl).second>(*itr).second)
    {
        return;
    }
    t[++cnt].l=(*itl).second;
    t[cnt].r=(*itr).second;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        int x0,v0,a;
        for(int i=1;i<=n;i++)
        {
            cin>>x0>>v0>>a;
            solve(x0,v0,a,i);
            //cout<<"~~"<<i<<" "<<ll[i]<<" "<<rr[i]<<endl;
        }
        s.clear();
        int x;
        for(int i=1;i<=m;i++)
        {
            cin>>x;
            s[x]=i;
        }
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(ll[i]<=rr[i])
            {
                add(ll[i],rr[i]);
            }
        }
        cout<<cnt<<" ";
        sort(t+1,t+cnt+1);
        int now=-1;
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            if(t[i].l<=now)
            {
                continue;
            }
            ans++;
            now=t[i].r;
            //cout<<"~~~"<<now<<endl;
        }
        cout<<m-ans<<endl;
    }
    return 0;
}
