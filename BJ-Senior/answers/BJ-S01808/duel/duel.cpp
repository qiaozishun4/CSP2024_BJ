#include<bits/stdc++.h>
using namespace std;
struct node{
    int bj,number;
};
node num[100005];
int n,bj1,sum,ans,cc[1000005];
bool cmp(node x,node y){
    return x.bj<y.bj;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i].bj);
        cc[num[i].bj]++;
    }
    sort(num+1,num+n+1,cmp);
    bj1=num[1].bj;
    sum=1;
    for(int i=2;i<=n;i++){
        if(num[i].bj>bj1&&cc[bj1]>0){
            ans--;
            cc[bj1]--;
            sum++;
        }
        if(cc[bj1]==0&&num[i+1].bj==num[i].bj){
            bj1=num[sum].bj;
            continue;
        }
        if(cc[bj1]>0&&num[i+1].bj!=num[i].bj){
            bj1=num[sum].bj;
            continue;
        }
        if(num[i+1].bj!=num[i].bj&&cc[bj1]==0){
            bj1=num[i].bj;
        }
    }
    printf("%d",ans);
    return 0;
}
