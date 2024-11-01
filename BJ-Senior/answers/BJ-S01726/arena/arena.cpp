#include <bits/stdc++.h>
using namespace std;
int T,n,m,c[100005];
long long a[100005],A[100005],qwq[200005];
string d[100005];
long long x[4];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    for(int i=1;i<=ceil(__lg(n))+1;i++) cin>>d[i];
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&x[0],&x[1],&x[2],&x[3]);
        for(int i=1;i<=n;i++) A[i]=a[i]^x[i%4];
        for(int i=1;i<=(1<<int(__lg(n)));i++) qwq[i+(1<<int(__lg(n)))-1]=i;
        for(int i=1;i<=(int)__lg(n);i++)
            for(int j=0;j<(1<<(int)__lg(n)-i);j++){
                int k=(1<<(__lg(n)-i))+j;
                if(d[i][j]=='0') qwq[k]=(A[qwq[k*2]]>=i?qwq[k*2]:qwq[k*2+1]);
                else qwq[k]=(A[qwq[k*2+1]]>=i?qwq[k*2+1]:qwq[k*2]);
            }
        long long ans=0;
        for(int i=1;i<=m;i++){
            if((c[i]&c[i]-1)==0) ans^=(qwq[1<<(__lg(n)-__lg(c[i]))]*i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
