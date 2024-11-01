#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        if(n%7==0){
            int num=n/7;
            for(int i=1;i<=num;i++)cout<<8;
            cout<<'\n';
        }else if((n-1)%7==0){
            cout<<"10";
            int num=(n-8)/7;
            for(int i=1;i<=num;i++)cout<<8;
            cout<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}
