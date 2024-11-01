#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,p[114514],d[114514],v[114514],a[114514],inttmpans,lcal;
int cal(){
    int mycalfuncres=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(p[j]>=d[i])if((v[i]*v[i]+2*a[i]*(p[j]-d[j]))>0)if(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[j]))>(V*1.0)){
        mycalfuncres++;
        break;
    }
    return mycalfuncres;
}
int main(){
    freopen("detect.in","r",stdin),freopen("detect.out","w",stdout),scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&l,&V),inttmpans=0,memset(p,0,sizeof p),memset(d,0,sizeof d),memset(v,0,sizeof v),memset(a,0,sizeof a);
        for(int i=1;i<=n;i++)scanf("%d%d%d",d+i,v+i,a+i);
        for(int i=1;i<=m;i++)scanf("%d",p+i);
        lcal=cal();
        for(int i=1;i<=m;i++)p[i]-=11919810,inttmpans+=(cal()==lcal),p[i]+=11919810;
        cout<<lcal<<' '<<inttmpans<<'\n';
    }
    return 0;
}