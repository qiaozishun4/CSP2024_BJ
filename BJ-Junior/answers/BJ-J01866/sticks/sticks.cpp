#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(t%7==0){
            for(int i=1;i<=t/7;++i) cout<<8;
            cout<<endl;
        }
        else{
            if(n!=1){
                cout<<10;
                for(int i=1;i<=t/7-1;++i) cout<<8;
                cout<<endl;
            }
            else{
                cout<<-1;
                cout<<endl;
            }
        }
    }
    return 0;
}
