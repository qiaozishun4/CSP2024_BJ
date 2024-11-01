#include<iostream>
using namespace std;
int n,ans;
int a[200005],zt[200005];
void dfs(int x){
    if(x>n){
        int flag1=0,flag2=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(zt[i]==0){
                if(a[i]==a[flag1]) cnt+=a[flag1];
                flag1=i;
            }
            else{
                if(a[i]==a[flag2]) cnt+=a[flag2];
                flag2=i;
            }
        }
        ans=max(ans,cnt);
        return ;
    }
    for(int i=0;i<=1;i++){
        zt[x]=i;
        dfs(x+1);
    }
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=15){
            dfs(1);
            cout<<ans<<'\n';
            ans=0;
        }
    }
    return 0;
}

//20pts finish time: 16:47
//luogu uid 453759
//BJ-S01147
//:(
//IcantAKCSPS
