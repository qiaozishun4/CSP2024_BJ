#include<bits/stdc++.h>
using namespace std;
const int p[8]={0,0,1,7,4,2,6,8};
int t,n,ans,num[101];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=1){
            printf("-1\n");
            continue;
        }
        ans=0;
        int i=0;
        while(n-7>=0) num[i++]=8;n-=7;
        if(n-7==1)
            num[i-1]=6;
            num[i]=1;
            for(int j=i;j>=0;j--) printf("%d",num[j]);
            printf("\n");
            continue;
        num[i]=p[n];
        for(int j=i;j>=0;j--) printf("%d",num[j]);
        printf("\n");
    }
    return 0;
}
