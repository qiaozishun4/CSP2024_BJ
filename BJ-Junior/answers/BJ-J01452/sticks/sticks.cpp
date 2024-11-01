#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) cout<<-1;
        else if((n-1)%7==0){
            cout<<1;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<0;
        }else{
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}