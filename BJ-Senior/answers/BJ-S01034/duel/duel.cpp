#include <bits/stdc++.h>
#define maxn 100055
using namespace std;
int n,a[maxn],ans=10000005,vis[maxn]={},dp[maxn],out[maxn]={};
/*inline int findx(int x){
    int l=1,r=n,mid;
    while(l<r){
        mid=(r+l)>>1;
        if(a[mid]<=x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l;
}*/
inline int dfs(int x,int y){
    if(y>ans){
        return ans;
    }
    if(x>n){
        return y;
    }
    int num=dfs(x+1,y),t;//num equals num if not atk,t equals num if atk, y means recent num
    num=min(num,y);
    for(int i=1;i<=n;i++){
        if((a[i]<a[x])&&(!vis[x])&&(!out[i])){
            vis[x]=1;
            out[i]=1;
            t=dfs(x+1,y-1);
            num=min(num,t);
            vis[x]=0;
            out[i]=0;
        }
    }
    return num;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int pan=0,cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //dp[i]=n;
        if((a[i]!=1)&&(a[i]!=2)){
            pan=1;
        }
        if(a[i]==1){
            cnt1++;
        }
        if(a[i]==2){
            cnt2++;
        }
    }
    if(pan){
        sort(a+1,a+1+n);
        ans=dfs(1,n);
    }else{
        if(cnt2>=cnt1){
            ans=cnt2;
        }else{
            ans=cnt2+abs(cnt2-cnt1);
        }
    }
    //cout<<1<<endl;

    //dp[0]=n;
    //cout<<1<<endl;
    /*for(int i=1;i<=n;i++){
        int y=findx(a[i]);
        if((y!=i)&&(!vis[i])){
            vis[i]=1;
            vis[y]=1;
            dp[i]=min(dp[i-1],dp[i]-1);
        }else{
            dp[i]=dp[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i]);
    }*/
    cout<<ans<<endl;
    return 0;
}

