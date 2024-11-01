#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N],ans,tmp;
int dp[N];
int main(){
    freopen("duel2.in","r",stdin);
    freopen("duel2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    a[0]=-1;
    a[n+1]=-1;
    for(int i=1;i<=n+1;i++){
        if(a[i]==a[i-1]){
            tmp++;
        }else{
            ans=max(ans,tmp);
            tmp=1;
        }
    }
    cout<<ans;
    return 0;
}
