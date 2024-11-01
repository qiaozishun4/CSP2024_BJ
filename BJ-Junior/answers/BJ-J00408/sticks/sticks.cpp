#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int ans[55]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
//int ans;
/*void dfs(int now,int k){
    if(k==1) return;
    if(k==0){
        ans=min(ans,now);
        return;
    }
    if(now>=ans) return;
    if(k>7){
        for(int i=0;i<=9;i++){
            if(i==3||i==5||i==9) continue;
            if(now==0&&i==0) continue;
            now=(now<<1)+(now<<3)+i;
            k-=a[i];
            dfs(now,k);
            k+=a[i],now=(now-i)/10;
        }
    }else{
        for(int i=0;i<=9;i++){
            if(i==3||i==5||i==9) continue;
            if(now==0&&i==0) continue;
            if(a[i]==k){
                ans=min(ans,now*10+i);
                return;
            }
        }
    }
}*/
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;
        if(n<=50){
            cout<<ans[n]<<'\n';
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else{
            while(n>50){
                n-=7,cnt++;
            }
            cout<<ans[n];
            for(int i=1;i<=cnt;i++) cout<<8;
            cout<<'\n';
        }
    }
    return 0;
}
