#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],c[N],b[N],d[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i),b[a[i]]++;
    for(int i=1;i<=100000;i++) 
        if(b[i]) c[++m]=b[i],d[m]=c[m];
    int tmp=1,ans=n;
    for(int i=2;i<=m;i++){
        if(d[i]){
            while(d[i]>=c[tmp]&&i>tmp){
                ans-=c[tmp],d[i]-=c[tmp],c[tmp]=0;
                tmp++;
            }
            if(d[i]<c[tmp]&&i>tmp) ans-=d[i],c[tmp]-=d[i],d[i]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}