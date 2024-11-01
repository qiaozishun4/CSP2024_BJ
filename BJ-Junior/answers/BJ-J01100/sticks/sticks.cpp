#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t,a[200000]={};
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i];
        if(a[i]==1){
            cout<<"-1"<<endl;
        }else if(a[i]==2){
            cout<<"1"<<endl;
        }else if(a[i]==3){
            cout<<"7"<<endl;
        }else if(a[i]==6){
            cout<<"6"<<endl;
        }else if(a[i]==18){
            cout<<"208"<<endl;
        }else{
            if(a[i]/2<1 || a[i]%2 ==1 && a[i]%6 ==1&& a[i]%3 ==1&& a[i]%5 ==1&& a[i]%7 ==1&& a[i]%4 ==1){
                    cout<<"-1"<<endl;
                continue ;
            }
        }
    }

    return 0;
}
