#include<bits/stdc++.h>
using namespace std;
int n,f[100005],e[10],r[10];
int ans[20005];
void init(){
    memset(f,127,sizeof(f));
    f[0]=0;
    for(int i=2;i<=7;i++){
        for(int j=i;j<=100000;j++){
            f[j]=min(f[j],f[j-i]+1);
        }
    }
    e[0]=0,e[1]=1,e[2]=2,e[3]=4,e[4]=6,e[5]=7,e[6]=8;
    r[0]=6,r[1]=2,r[2]=5,r[4]=4,r[6]=6,r[7]=3,r[8]=7;
}
void solve(){
    scanf("%d",&n);
    if(f[n]==f[100001]){
        printf("-1\n");
        return;
    }
    for(int i=1;i<=6;i++){
        int z=r[e[i]];
        if(n<z)continue;
        if(f[n-z]+1==f[n]){
            ans[1]=e[i],n-=z;
            break;
        }
    }
    int l=1;
    while(n!=0){
        for(int i=0;i<=6;i++){
            int z=r[e[i]];
            if(n<z)continue;
            if(f[n-z]+1==f[n]){
                ans[++l]=e[i],n-=z;
                break;
            }
        }
    }
    for(int i=1;i<=l;i++)printf("%d",ans[i]);
    printf("\n");
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    init();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}