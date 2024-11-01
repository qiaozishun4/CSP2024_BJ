#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,m,l,V;
int d[100005],v[100005],a[100005],b[100005];
int p[100005];
bool flag1,flag2,flag3;
struct node
{
    int l,r;
    bool friend operator < (node x,node y)
    {
        if(x.r!=y.r)return x.r>y.r;
        return x.l>y.l;
    }
};
int main()
{
    freopen("detect2.in","r",stdin);
    freopen("detect2.out","w",stdout);
    cin>>t;
    while(t--)
    {
        flag1=flag2=flag3=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0)flag2=flag3=1;
            if(a[i]==0)flag1=flag3=1;
            if(a[i]<0)flag1=flag2=1;
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        sort(p+1,p+m+1);
        if(!flag1)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(d[i]>p[m])continue;
                int diss=p[m]-d[i];
                if(v[i]*v[i]+2*a[i]*diss>V*V)cnt++;
            }
            if(cnt)cout<<cnt<<' '<<m-1<<endl;
            else cout<<cnt<<' '<<m<<endl;
        }
        if(!flag2)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(v[i]>V&&d[i]<=p[m])cnt++;
            }
            if(cnt)cout<<cnt<<' '<<m-1<<endl;
            else cout<<cnt<<' '<<m<<endl;
        }
        if(n<=3000&&m<=3000)
        {
            int maxax=0,ans=0,cnt=0,kkksc03=0;
            priority_queue<node> pq;
            queue<node> q;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>=0)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(d[i]>p[j])continue;
                        int diss=p[j]-d[i];
                        if(v[i]*v[i]+2*a[i]*diss>V*V)
                        {
                            cnt++;
                            ans=1;
                            maxax=max(maxax,j);
                            break;
                        }
                    }
                }
                if(a[i]<0)
                {
                    if(v[i]<V)continue;
                    int ll=0,rr=0;
                    for(int j=1;j<=m;j++)
                    {
                        if(d[i]>p[j])continue;
                        int diss=p[j]-d[i];
                        if(v[i]*v[i]+2*a[i]*diss>V*V)
                        {
                            if(ll==0)ll=j;
                            rr=j;
                        }
                    }
                    if(ll==0&&rr==0)continue;
                    if(ll<=maxax&&maxax<=rr)cnt++;
                    else pq.push({ll,rr}),cnt++;
                }
            }
            while(pq.size())
            {
                node u=pq.top();
                if(u.r>maxax&&maxax!=0&&kkksc03==0)
                {
                    ans--;
                    kkksc03=1;
                }
                pq.pop();
                while(pq.size())
                {
                    node v=pq.top();
                    pq.pop();
                    if(v.l<=u.r&&v.r>=u.r)1;
                    else q.push(v);
                }
                while(q.size())
                {
                    pq.push(q.front());
                    q.pop();
                }
                ans++;
                //cout<<pq.size()<<endl;
            }
            cout<<cnt<<' '<<m-ans<<endl;
        }
    }
    return 0;
}
