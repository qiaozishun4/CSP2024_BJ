#include<bits/stdc++.h>
using namespace std;
int b[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a,tmp=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        b[a]++;
    }
    for(int i=1;i<=100000;i++){
        tmp=max(tmp,b[i]);
    }
    printf("%d",tmp);
    return 0;
}