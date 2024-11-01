#include<bits/stdc++.h>
using namespace std;
int t,n,k=1,f=0,p[100010],a[]={6,2,5,5,4,5,6,3,7,6};
void dfs(int x,int sum){
    if(f==1){
        return;
    }
    if(sum>n){
        return;
    }
    if(x>k){
        if(sum==n){
            for(int i=1;i<=k;i++){
                cout<<p[i];
            }
            cout<<endl;
            f=1;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        if(i==0 && x==1){
            continue;
        }
        p[x]=i;
        dfs(x+1,sum+a[i]);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0 && n>=100){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1 && n>=100){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        f=0;
        k=1;
        for(;f==0;k++){
            dfs(1,0);
        }
    }
    return 0;
}

