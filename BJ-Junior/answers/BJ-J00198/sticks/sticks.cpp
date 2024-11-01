#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int shushu[100]={6,2,5,5,4,5,6,3,7,6};
bool dfs(int cnt,int ant){
    if(cnt==1){
        for(int i=0;i<=9;i++){
            if(ant==shushu[i]){
                    ant=ant*10+shushu[i];
                return 1;
            }
        }
    }
    for(int i=0;i<=9;i++){
        if(dfs(cnt-1,ant-shushu[i])==1){
            ans=ans*10+shushu[i];
            return 1;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(dfs(n/7+1,n)==1){
            cout<<ans<<endl;
        }
    }
    return 0;
}
