#include <bits/stdc++.h>
using namespace std;
int n;
char ans[1000005];
int a[]={10000,10000,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("-1\n");
            continue;
        }
        int k=n;
        n=n%7; if(n==0) n=7;
        int minid=0;
        a[6]=6;
        for(int i=n;i<=7;i++) if(a[i]<a[minid]) minid=i;
        n=minid-n;
        printf("%d",a[minid]);
        a[6]=0;
        for(int i=k/7-(k%7==0);i>=1;i--){
            minid=0;
            for(int j=7-n;j<=7;j++) if(a[j]<a[minid]) minid=j;

            if(i!=1)printf("%d",a[minid]);
            else printf("%d",a[7-n]);
            n-=(7-minid);
        }
        printf("\n");
    }
    return 0;
}