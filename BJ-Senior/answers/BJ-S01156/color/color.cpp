#include <bits/stdc++.h>
#define LL long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int MAXN=2e5+5;
int T,N,a[MAXN];
LL dp[MAXN][2];//i is the end of a red/blue range, while the contribution of i+1 is considered
LL sam[MAXN];
LL mx[2][MAXN<<2],add[2][MAXN<<2];
void Up(int t,int p)
{
    mx[t][p]=max(mx[t][ls],mx[t][rs]);
    return;
}
void Down(int t,int p)
{
    if(!add[t][p]) return;
    add[t][ls]+=add[t][p],add[t][rs]+=add[t][p];
    mx[t][ls]+=add[t][p],mx[t][rs]+=add[t][p];
    add[t][p]=0;
    return;
}
void Add(int t,int p,int l,int r,int ql,int qr,LL k)
{
    if(ql<=l&&r<=qr)
    {
        mx[t][p]+=k;
        add[t][p]+=k;
        return;
    }
    int mid=(l+r)>>1;
    Down(t,p);
    if(ql<=mid) Add(t,ls,l,mid,ql,qr,k);
    if(mid<qr) Add(t,rs,mid+1,r,ql,qr,k);
    Up(t,p);
    return;
}
void Modify(int t,int p,int l,int r,int q,LL k)
{
    if(l==r)
    {
        mx[t][p]=k;
        add[t][p]=0;
        return;
    }
    int mid=(l+r)>>1;
    Down(t,p);
    if(q<=mid) Modify(t,ls,l,mid,q,k);
    else Modify(t,rs,mid+1,r,q,k);
    Up(t,p);
    return;
}
int pre[MAXN],mxv[MAXN*5];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
  //  printf("%d\n",T);
    while(T--)
    {
        //puts("qwq");
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        for(int i=1;i<=N;i++) mxv[a[i]]=0;
        for(int i=1;i<=N;i++) 
        {
            if(!mxv[a[i]]) pre[i]=0;
            else pre[i]=mxv[a[i]];
            mxv[a[i]]=i;
        }
        for(int i=1;i<=N;i++) sam[i]=sam[i-1]+a[i]*(a[i]==a[i-1]);
        for(int i=1;i<=4*N;i++) add[0][i]=add[1][i]=mx[0][i]=mx[1][i]=0;
        for(int i=1;i<=N;i++) dp[i][0]=sam[i],dp[i][1]=0;
        Modify(0,1,1,N,1,dp[1][0]);
        for(int i=2;i<=N;i++)
        {
            /*for(int j=1;j<i;j++)
            {
                dp[i][0]=max(dp[i][0],dp[j][1]+sam[i]-sam[j+1]+a[i+1]*(a[i+1]==a[j]));
                dp[i][1]=max(dp[i][1],dp[j][0]+sam[i]-sam[j+1]+a[i+1]*(a[i+1]==a[j]));
            }*/
            Add(0,1,1,N,1,N,sam[i]-sam[i-1]);
            Add(1,1,1,N,1,N,sam[i]-sam[i-1]);
            dp[i][0]=max(dp[i][0],mx[1][1]);
            dp[i][1]=max(dp[i][1],mx[0][1]);
            if(i!=N&&pre[i+1])
            {      
                dp[i][0]=max(dp[i][0],dp[pre[i+1]][1]+sam[i]-sam[pre[i+1]+1]+a[i+1]);
                dp[i][1]=max(dp[i][1],dp[pre[i+1]][0]+sam[i]-sam[pre[i+1]+1]+a[i+1]);
            }
            Modify(0,1,1,N,i,dp[i][0]);
            Modify(1,1,1,N,i,dp[i][1]);
        }
        printf("%lld\n",max(dp[N][0],dp[N][1]));
    }
    return 0;
}