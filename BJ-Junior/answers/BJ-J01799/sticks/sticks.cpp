#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n;
    cin>>n;
    int s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s==1){
            cout<<-1;
            continue;
        }
        if(s%7==0){
            for(int j=1;j<=s/7;j++){
                cout<<8;
            }
            continue;
        }
        if(s%7==1){
            cout<<10;
            for(int k=1;k<=(s-8)/7;k++){
                cout<<8;
            }
            continue;
        }
        if(s%7==6){
            cout<<6;
            for(int l=1;l<=(s-6)/7;l++){
                cout<<8;
            }
            continue;
        }
    }
    return 0;
}
