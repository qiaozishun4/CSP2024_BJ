#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
