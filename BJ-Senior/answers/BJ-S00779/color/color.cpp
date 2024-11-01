#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7,M=20007;
int t;
int n,o;
ll a[N],ans,rd[2][M],bl[2][M];
inline ll w(int x,int y){
    if(a[x]==a[y])return a[x];
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=-1;
        memset(bl,0,sizeof bl),memset(rd,0,sizeof rd);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            o^=1;
            memset(rd[o],0,sizeof rd[o]),memset(bl[o],0,sizeof bl[o]);
            for(int j=0;j<i-1;j++)rd[o][j]=rd[o^1][j]+w(i-1,i),bl[o][j]=bl[o^1][j]+w(i-1,i);
            for(int k=0;k<i-1;k++)bl[o][i-1]=max(bl[o][i-1],bl[o^1][k]+w(i,k)),rd[o][i-1]=max(rd[o][i-1],rd[o^1][k]+w(i,k));
        }
        for(int i=0;i<=n;i++)ans=max(ans,max(bl[o][i],rd[o][i]));
        printf("%lld\n",ans);
    }
    return 0;
}
