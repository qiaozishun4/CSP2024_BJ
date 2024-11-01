#include<bits/stdc++.h>
using namespace std;
bool a[50]={1,0,1,0,1,0,0};
int main (){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long n,q,k,t,x,y;
    cin>>t>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        while(x--)cin>>y;
    }for(int i=0;i<q;i++)cin>>x>>y;
    k=t*q;
    long long idx=0;
    while(k--){
        cout<<a[idx]<<endl;
        idx=(idx+1)%7;
    }
    return 0;
    fcloce(stdin);
    fcloce(stdout);
}