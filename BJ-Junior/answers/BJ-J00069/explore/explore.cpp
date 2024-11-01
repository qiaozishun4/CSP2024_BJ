#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];bool c[1010][1010];
pair <long long,long long> p[5]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long n,m,k,T,x,y,d,ans;
    scanf("%lld",&T);
    while(T--){
        ans=0;
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;j++) c[i][j]=0;
		}
        for(int i=1;i<=k;i++){
			if(c[x][y]==0){
				ans++;
				c[x][y]=1;
			}
            long long t1=x+p[d].first,t2=y+p[d].second;
            if(t1>n || t1<1 || t2>m || t2<1 || a[t1][t2]=='x') d=(d+1)%4;
            else if(a[t1][t2]=='.'){
                x=t1;
                y=t2;
            }
            if(c[x][y]==0){
				ans++;
				c[x][y]=1;
			}
        }
        printf("%lld\n",ans);
    }
    return 0;
}

