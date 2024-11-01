#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n,a[N],vis1[N],vis2[N],ans,sum1=0,sum2=0;    //vis1表示是否攻击 vis2表示是否死亡

void check(){
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            bool flag=0;
            if(a[j]<a[i]&&vis2[j]!=0){
                vis2[j]=0;
                vis1[i]=0;
                flag=1;
            }
            if(flag) break;
        }
    }
}

int main(){
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) vis1[i]=1,vis2[i]=1;
    sort(a+1,a+1+n);
    if(n>=100000){
        for(int i=1;i<=n;i++) {
            if(a[i]==1) sum1++;
            else if(a[i]==2) sum2++;
        }
        if(sum2>=sum1) printf("%d",sum2);
        else{
            printf("%d",sum1);
        }
    }else{
        while(1){
            if(vis1[n]==0){
                for(int i=1;i<=n;i++){
                    if(vis2[i]==1) ans++;
                }
                printf("%d",ans);
                return 0;
            }
            check();
        }
    }
    return 0;
}
