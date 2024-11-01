#include<bits/stdc++.h>
using namespace std;
int biao[100001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        scanf("%d",&biao[i]);
    }
    sort(biao+1,biao+a+1,cmp);
    for(int i=a;i>=1;i--){
        if(biao[i]==-1){
            continue;
        }
        for(int j=i;j<=a;j++){
            if(biao[j]==-1) continue;
            if(biao[i]>biao[j]){
                biao[j]=-1;
                break;
            }
        }
    }
    long long da=0;
    for(int i=1;i<=a;i++){
        if(biao[i]!=-1) da++;
    }
    printf("%d",da);
    return 0;
}
