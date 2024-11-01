#include<iostream>
#include<cstdio>
using namespace std;
int n,r,ans,a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r);
        a[r]++;
    }
    for(int i=1;i<=1e5;i++) if(a[i]>ans) ans=a[i];
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
