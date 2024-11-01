#include<bits/stdc++.h>
#define lson (u<<1)
#define rosn (u<<1)|1
using namespace std;
const int N=150005;
int n,m;
int K;
int aa[N];
int a[N],bb[N];
int vl[N];
int g[20][N];
int rd[20][N];
int mx[N];
long long b[4];
long long c[N];
long long num[N];
long long calc(long long l,long long r)
{
    return (l+r+2)*(r-l+1)/2;
}
int find(int rdd,int l,int r)
{
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)>>1;
    int lval=find(rdd-1,l,mid);
    int rval=find(rdd-1,mid+1,r);
    
    if(g[rdd][rd[rdd][mid]]==0)
    {
        if(a[lval]>=rdd)
        {
            return lval;
            
        }
        else
        {
            return rval;
        }
    }
    else
    {
        if(a[rval]>=rdd)
        {
            return rval;
        }
        else 
        {
            return lval;
        }
    }
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>aa[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=17;j++)
        {
            if((1<<j)>=(i+1))
            {
                mx[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
        c[i]--;
        num[c[i]]=i;
    }
    for(int i=0;i<=17;i++)
    {
        if((1<<i)>=n)
        {
            K=i;
            break;
        }
    }
    for(int i=1;i<=K;i++)
    {
        for(int j=0;j<(1<<(K-i));j++)
        {
			char c;
			cin>>c;
			g[i][j]=c-'0';
            //cin>>g[i][j];
        }
    }
    for(int i=0;i<n;i++)rd[0][i]=i;
    for(int j=1;j<=K;j++)
    {
        for(int i=0;i<n;i++)
        {
            rd[j][i]=rd[j-1][i]>>1;
        }
    }
    int _;
    cin>>_;
    cerr<<K;
    while(_--)
    {
        for(int i=0;i<4;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            a[i]=(aa[i+1]^b[(i+1)%4]);
        }
        for(int i=n;i<(1<<K);i++)a[i]=0;

        long long ans=0;
        
        for(int i=0;i<n;i++)
        {

            if(num[i])
            {
                bitset<5005>tp;
                tp=0;
                long long val=0;
                for(int j=i;j<(1<<mx[i]);j++)
                {
                    for(int k=0;k<=i;k++)
                    {
                        a[k]=(aa[k+1]^b[(k+1)%4]);
                    }
                    for(int k=i+1;k<(1<<mx[i]);k++)a[k]=0;
                    if(j<=i)
                    {
                        tp[find(mx[i],0,(1<<mx[i])-1)]=1;
                    }
                    else
                    {
                        a[j]=105;
                        tp[find(mx[i],0,(1<<mx[i])-1)]=1;
                    }
                }
                for(int j=0;j<n;j++)
                {
                    if(tp[j])val+=(j+1);
                }
                ans^=val*num[i];
            }
        }
        cout<<ans<<'\n';
    }
}
