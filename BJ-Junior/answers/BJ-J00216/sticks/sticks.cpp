#include<bits/stdc++.h>
using namespace std;
int t,nn,ans,a[10]={6,2,5,5,4,5,6,3,7,6};
int dfs(int n,int an,int f){
    if(n==0){
        if(an>=0&&ans>0){
        ans=min(ans,an);
        }
        return 0;
    }
    if(f==0){
        for(int i=1;i<10;i++){
            if(n-a[i]>=0)
            dfs(n-a[i],an*10+i,1);
        }
    }else{
        for(int i=0;i<10;i++){
            if(n-a[i]>=0)
            dfs(n-a[i],an*10+i,1);
        }
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>nn;
        ans=1e9;
        int aa=dfs(nn,0,0);
        if(ans==1e9)cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}