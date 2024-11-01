#include<bits/stdc++.h>
using namespace std;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int n;
int T;
int a[100005];
long long ans;
void DFS(int nn,int x){
    if(nn==0){
        long long sum=0;
        for(int i=1;i<x;i++) sum=sum*10+a[i];
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<=9;i++){
        if(x==1 && i==0) continue;
        if(nn>=num[i]){
            a[x]=i;
            DFS(nn-num[i],x+1);
            a[x]=0;
        }
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        ans=LONG_MAX;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        DFS(n,1);
        if(ans!=LONG_MAX) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
