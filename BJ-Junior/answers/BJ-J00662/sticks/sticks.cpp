#include<bits/stdc++.h>
using namespace std;
long long n,zd;
void dfs(long long c,long long s,int k){
    if(s==n){
        zd=min(zd,c);
    }if(s>n){
        return;
    }
    if(k!=1){
        dfs(c*10,s+6,2);
    }dfs(c*10+1,s+2,2);
    dfs(c*10+2,s+5,2);
    dfs(c*10+3,s+5,2);
    dfs(c*10+4,s+4,2);
    dfs(c*10+5,s+5,2);
    dfs(c*10+6,s+6,2);
    dfs(c*10+7,s+3,2);
    dfs(c*10+8,s+7,2);
    dfs(c*10+9,s+6,2);
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){

        cin>>n;
        if(n>=100){
            if(n%7==0){
                for(int j=1;j<=n/7;j++) cout<<8;
                cout<<endl;
            }else{
                cout<<-1<<endl;
            }
        }else if(n<=20){
            zd=11466666514;
            dfs(0,0,1);
            if(zd==11466666514) cout<<-1<<endl;
            else cout<<zd<<endl;
        }else cout<<-1;
    }
    return 0;
}
