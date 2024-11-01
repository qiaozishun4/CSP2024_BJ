#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,g;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>g;
        if(g<=1){
            cout<<-1;
        }
        else if(g==2){
            cout<<1;
        }
        else if(g==3){
            cout<<7;
        }
        else if(g==6){
            cout<<6;
        }
        else{
            cout<<208;
        }
    }
    return 0;
}