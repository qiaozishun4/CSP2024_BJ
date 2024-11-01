#include<bits/stdc++.h>
using namespace std;
long long t,ans;
int a[10]={6,2,5,5,4,5,6,3,7,6},n;
void f(int sum,long long num){
    if(sum==0){
        if(num<ans){
            ans=num;
        }
        return ;
    }
    for(int i=0;i<=9;i++){
        if(sum>=a[i]){
            f(sum-a[i],num*10+i);
        }
    }
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        ans=2e9;
        cin>>n;
        for(int i=1;i<=9;i++){
            if(n>=a[i]){
                f(n-a[i],i);
            }
        }
        if(ans==2e9){
            cout<<-1<<'\n';
        }else{
            cout<<ans<<'\n';
        }
    }
}
