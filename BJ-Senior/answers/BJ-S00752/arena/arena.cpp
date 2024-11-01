#include<bits/stdc++.h>
using namespace std;
int a[100005],now,n,tot=1,K;
bool need=0;
struct query
{
    int q,id;
}q[100005];
bool cmp(query x,query y)
{
    return x.q<y.q;
}
bool d[30][100005];
long long ans[100005];
bool vis2[5005];
vector<int>vis[30][5005];
void update(int k,int ch)
{
    vis[k][ch].clear();
    for(int i=1;i<=tot;i++)
        vis2[i]=0;
    for(int i=0;i<vis[k-1][ch*2].size();i++)
    {
        for(int j=0;j<vis[k-1][ch*2-1].size();j++)
        {
            int x=vis[k-1][ch*2][i],y=vis[k-1][ch*2-1][j];
            if(x>y) swap(x,y);
            if(d[k][ch]) swap(x,y);
            if(x>min(now,n)) vis2[x]=vis2[y]=1;
            else if(a[x]>=k) vis2[x]=1;
            else vis2[y]=1;
        }
    }
    for(int i=1;i<=tot;i++)
        if(vis2[i])
            vis[k][ch].push_back(i);
    if(need&&k+1<=K) update(k+1,(ch+1)/2);
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].q;
        q[i].id=i;
    }
    while(tot<n)
    {
        tot*=2;
        K++;
    }
    int temp=tot;
    for(int i=1;i<=K;i++)
    {
        temp/=2;
        char x;
        for(int j=1;j<=temp;j++)
        {
            cin>>x;
            d[i][j]=x-'0';
        }
    }
    sort(q+1,q+m+1,cmp);
    temp=1;
    int t;
    cin>>t;
    while(t--)
    {
        long long ans2=0;
        int x[5];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
            a[i]=(a[i]^x[i%4]);
        for(int i=1;i<=tot;i++)
        {
            vis[0][i].push_back(i);
            need=0;
            int temp2=i,cnt=0;
            while(temp2%2==0)
            {
                cnt++,temp2/=2;
                update(cnt,temp2);
            }
        }
        int l=1,r;
        for(int i=0;i<=K;i++)
        {
            for(int j=l;q[j].q<=temp&&j<=m;j++)
                r=j;
            for(int j=l;j<=r;j++)
            {
                while(now<q[j].q)
                {
                    need=0;
                    if(now%2==1) now++;
                    else now+=2;
                    int temp2=now,cnt=0;
                    while(temp2%2==0)
                    {
                        cnt++,temp2/=2;
                        update(cnt,temp2);
                    }
                }
                need=1;
                now=q[j].q;
                update(1,(now+1)/2);
                for(int j2=0;j2<vis[i][1].size();j2++)
                    ans[q[j].id]+=vis[i][1][j2];
            }
            l=r+1;
            temp=temp*2;
        }
        for(int i=1;i<=m;i++)
            ans2=(ans2^(ans[i]*i));
        cout<<ans2<<endl;
    }
    return 0;
}
