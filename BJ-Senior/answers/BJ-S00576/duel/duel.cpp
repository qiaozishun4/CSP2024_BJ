#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int num;
    int bigger;
}a[100010];
bool tmp(node xx,node yy){
    return xx.num<yy.num;
}
int ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%d",&a[i].num);
    }
    sort(a+1,a+n+1,tmp);
    int ls=0;
    for(int i=2;i<=n;i++){
        if(a[i-1].num==a[i].num){
            a[i].bigger=a[i-1].bigger;
        }
        else{
            a[i].bigger=i-1;
        }
        if(a[i].bigger-ans>0){
            ans++;
        }
    }
    printf("%d",n-ans);
    return 0;
}

