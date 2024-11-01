#include<bits/stdc++.h>
using namespace std;
int n;
int ans=100000000;
int a[100001];
void dfs(int now,int tot,int all){
    ans=-1;
    ans=min(ans,tot);
    if(all==0){
        ans=tot;
    }
    int b=all;
    if(now!=0&&all-6>=0){
        dfs(now+1,tot*10+0,all-6);
    }else if(all-7>=0){
        dfs(now+1,tot*10+8,all-8);
    }else if(all-5>=0){
        dfs(now+1,tot*10+2,all-5);
    }else if(all-4>=0){
        dfs(now+1,tot*10+4,all-4);
    }else if(all-3>=0){
        dfs(now+1,tot*10+7,all-3);
    }else if(all-2>=0){
        dfs(now+1,tot*10+2,all-2);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dfs(0,0,a[i]);
        cout<<ans<<endl;
    }
    return 0;
}
