#include<bits/stdc++.h>
using namespace std;

int n;
int r[100002];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",r+i);
    }
    sort(r+1,r+n+1);
    int ans=0,cnt=1;
    for(int i=1;i<=n;i++){
        if(r[i]==r[i+1]){
            cnt++;
        }
        else{
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    printf("%d",max(ans,cnt));
    return 0;
}
