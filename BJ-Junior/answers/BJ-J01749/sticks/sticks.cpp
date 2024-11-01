#include<bits/stdc++.h>
using namespace std;
int n,t,maxn=0x7f7f7f7f;
void dfs(int l,int sum){
    if(l==0){
        if(sum>maxn)maxn=sum;
    }
    if(l==1||l<=0)return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==0||n==1)cout<<"-1"<<endl;
        else if(n==2)cout<<'1'<<endl;
        else if(n==3)cout<<'7'<<endl;
        else if(n==4)cout<<'4'<<endl;
        else if(n==5)cout<<'2'<<endl;
        else if(n==6)cout<<'6'<<endl;
        else if(n==7)cout<<'8'<<endl;
        int l=n/7+1;
        if(n%7==0)l--;
        dfs(l,0);
    }
    return 0;
}
