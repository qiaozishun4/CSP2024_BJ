#include<bits/stdc++.h>
using namespace std;
int n,m,K;
int aa[100010],a[100010];
int c[100010];
int d[20][(1<<16)+10];
int now[(1<<17)+10],gt[(1<<17)+10];
bool vis[(1<<18)+10];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    K=(n==1?0:__lg(n-1)+1);
    for(int i=1; i<=n; ++i) cin>>aa[i];
    for(int i=1; i<=m; ++i) cin>>c[i];
    for(int i=1; i<=K; ++i)
    {
        string s; cin>>s;
        for(int j=1; j<=(1<<K-i); ++j) d[i][j]=s[j-1]-'0';
    }
    int t; cin>>t; while(t--)
    {
        int x[4]; cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1; i<=n; ++i) a[i]=aa[i]^x[i%4];
        long long aans=0;
        for(int i=1; i<=m; ++i)
        {
            int k=(c[i]==1?0:__lg(c[i]-1)+1);
            for(int j=1; j<=c[i]; ++j) now[j]=a[j];
            for(int j=c[i]+1; j<=(1<<k); ++j) now[j]=-1;
            memset(vis,0,(1<<k+1)+5);
            for(int j=1; j<=k; ++j)
            {
                for(int l=1; l<=(1<<k-j); ++l)
                {
                    int wz=2*l-(d[j][l]==0);
                    if(now[wz]!=-1)
                    {
                        if(now[wz]>=j) gt[l]=now[wz],vis[(1<<k-j+1)+(d[j][l]==0?wz+1:wz-1)-1]=1;
                        else gt[l]=now[d[j][l]==0?wz+1:wz-1],vis[(1<<k-j+1)+wz-1]=1;
                    }
                    else gt[l]=-1;//gt[l]=(now[d[j][l]==0?wz+1:wz-1]<j?now[d[j][l]==0?wz+1:wz-1]:-1);
                }
                for(int l=1; l<=(1<<k-j); ++l) now[l]=gt[l];
            }
            for(int j=1; j<=(1<<k+1)-1; ++j) vis[j]|=vis[j/2];
            long long ans=0;
            for(int j=1; j<=(1<<k); ++j)
            {
                if(vis[(1<<k)+j-1]) continue;
                if(j>c[i] || a[j]>=k) ans+=j;
                else
                {
                    int now=j;
                    bool vis=0;
                    for(int l=1; l<=k; ++l)
                    {
                        if(l>a[j] && d[l][(now+1)/2]==(now%2==1?0:1)) { vis=1; break; }
                        now=(now+1)/2;
                    }
                    if(!vis) ans+=j;
                }
            }
            aans^=i*ans;
        }
        cout<<aans<<'\n';
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int get_k(int x) { return x==1?0:__lg(x-1)+1; }
int n,m,K;
int aa[100010],a[100010];
pair<int,int> c[100010];
int ans[100010];
int d[20][(1<<16)+10];
int now[(1<<18)+10];
bool vis[(1<<18)+10];
int ok[100010];
int main()
{
    freopen("arena.in","r",stdin);
    //freopen("arena.out","w",stdout);
    cin>>n>>m;
    K=get_k(n);
    for(int i=1; i<=n; ++i) cin>>aa[i];
    for(int i=1; i<=m; ++i) cin>>c[i].first,c[i].second=i;
    sort(c+1,c+m+1);
    for(int i=1; i<=K; ++i)
    {
        string s; cin>>s;
        for(int j=1; j<=(1<<K-i); ++j) d[i][j]=s[j-1]-'0';
    }
    int t; cin>>t; while(t--)
    {
        int x[4]; cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1; i<=n; ++i) a[i]=aa[i]^x[i%4];
        for(int i=1; i<=n; ++i)
        {
            ok[i]=1e9;
            int now=i;
            for(int j=1; j<=K; ++j)
            {
                if(j>a[i] && d[j][(now+1)/2]==(now%2==1?0:1)) { ok[i]=j; break; }
                now=(now+1)/2;
            }
        }
        long long aans=0;
        for(int i=1; i<=m; ++i)
        {
            int nnow=i;
            while(nnow<=m && get_k(c[nnow].first)==get_k(c[i].first)) ++nnow;
            --nnow;
            cout<<"range: "<<i<<' '<<nnow<<'\n';
            int k=get_k(c[i].first);
            set<int> st;
            long long ans=0;
            for(int j=1; j<=(1<<k); ++j) st.insert(j),ans+=j;
            for(int j=1; j<=(1<<k+1)-1; ++j) now[j]=-1;
            int wz=1;
            while(i<=nnow)
            {
                while(wz<=c[i].first)
                {
                    if(ok[wz]<=k && st.find(wz)!=st.end()) st.erase(wz);
                    int wwz=(1<<k)+wz-1;
                    now[wwz]=a[wz];
                    for(int j=1; j<=k; ++j)
                    {
                        int gt=wwz/2,ano=(wwz%2==0?wwz+1:wwz-1);
                        if(now[wwz]!=-1)
                        {
                            int l,r;
                            if(now[wwz]>=j) now[gt]=now[wwz],l=ano*(1<<k-j),r=(ano+1)*(1<<k-j)-1;
                            else now[gt]=now[ano],l=wwz*(1<<k-j),r=(wwz+1)*(1<<k-j)-1;
                            l=l-(1<<k)+1,r=r-(1<<k)+1;
                            cout<<"l,r: "<<l<<' '<<r<<'\n';
                            auto wz=st.lower_bound(l);
                            while(wz!=st.end() && (*wz)<=r) ans-=*wz,wz=st.erase(wz);
                        }
                        else now[gt]=-1;
                    }
                    ++wz;
                }
                for(int j=1; j<=(1<<k+1)-1; ++j) cout<<now[j]<<' ';
                cout<<'\n';
                cout<<"ans: "<<ans<<' '<<c[i].first<<' '<<c[i].second<<'\n';
                aans^=ans*c[i].second;
                ++i;
            }
            --i;
        }
        cout<<aans<<'\n';
    }
    return 0;
}

*/
