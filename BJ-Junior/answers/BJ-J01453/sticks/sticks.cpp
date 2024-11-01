#include <bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
long long ans[10000000];
long long n,a,minn;
void dfs(int a,int step,int now,int ans){
    if(now==a){
        if(ans<minn) minn=ans;
        return ;
    }
    if(step==1){
        for(int i=1;i<=9;i++){
            if(now+num[i]==a)
            dfs(a,step+1,now+=num[i],ans*10+i);
        }
    }
    else{
        for(int i=0;i<=9;i++){
            if(now+num[i]==a)
            dfs(a,step+1,now+=num[i],ans*10+i);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
         long long a;
         cin>>a;
         minn=9999999999999;
         if(a%2==0||a%3==0||a%5==0||a%7==0){
            dfs(a,1,0,0);
            ans[i]=minn;
         }
         else ans[i]=-1;
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans[n];
    return 0;
}
