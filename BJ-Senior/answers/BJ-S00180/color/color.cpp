#include<bits/stdc++.h>
using namespace std;
int T;
int a[200010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int maxx=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[0]=0x7fffffff;
        for(int i=0;i<1<<n+1;i++){
            int r=0,b=0,suma=0,sumb=0;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    if(a[j]==a[r])suma+=a[j];
                    r=j;
                }
                else {
                    if(a[j]==a[b])sumb+=a[j];
                    b=j;
                }
            }
            maxx=max(maxx,suma+sumb);
        }
        printf("%d",maxx);
    }
    return 0;
}
