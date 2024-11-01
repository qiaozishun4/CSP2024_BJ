#include<bits/stdc++.h>
using namespace std;
int T,n;
char stick[10]={6,2,5,5,4,5,6,3,7,6};
int sticknumber(int x){
    int res=0;
    while(x>=10){
        int temp=x%10;
        x/=10;
        res+=stick[temp];
    }
    res+=stick[x];
    return res;
}
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","r",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans=-1;
        for(int i=1;i<=100000;++i){
            if(sticknumber(i)==n){
                ans=i;
                break;
            }
        }
        printf("%d",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}