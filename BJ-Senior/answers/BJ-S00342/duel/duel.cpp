#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,tmp,r[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        r[tmp]++;
    }
    int rem=0;
    for(int i=1;i<=100000;i++){
        rem-=r[i];
        if(rem<0) rem=0;
        rem+=r[i];
    }
    printf("%d",rem);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
