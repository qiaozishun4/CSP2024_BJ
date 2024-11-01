#include<bits/stdc++.h>
using namespace std;
#define N 10002
int t,n;
int a[N];
bool c[N];
long long aans;
long long solveee(){
    int red0=0,blue1=0;
    long long aaans=0;
    for(int i=1;i<=n;i++){
        if(c[i]){
            if(blue1==0) blue1=i;
            else{
                if(a[blue1]==a[i]) aaans+=a[i];
                blue1=i;
            }
        }
        else{
            if(red0==0) red0=i;
            else{
                if(a[red0]==a[i]) aaans+=a[i];
                red0=i;
            }
        }
    }
    return aaans;
}
void solvee(int pp){
    if(pp==n+1){
        aans=max(aans,solveee());
        return;
    }
    c[pp]=0;
    solvee(pp+1);
    c[pp]=1;
    solvee(pp+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        aans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        solvee(1);
        printf("%lld\n",aans);
    }
    return 0;
}
