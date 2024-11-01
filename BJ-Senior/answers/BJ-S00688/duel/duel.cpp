#include<iostream>
using namespace std;
int main(){
    int n,cnt=0,i,x;
    for(i=1;i<=n;i++){
        cin>>x;
        if(x==2){
            cnt++;
        }
    }
    if(cnt<n/2){
        cout<<n-cnt;
    }
    else if(cnt==n){
        cout<<0;
    }
    else{
        cout<<n;
    }
}