#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2) cout<<-1;
        if(n==2) cout<<1;
        else if(n==3) cout<<7<<endl;
        else if(n==4) cout<<5<<endl;
        else if(n==5) cout<<3<<endl;
        else if(n==6) cout<<0<<endl;
        else{
            cout<<(n-1)/7<<endl;
        }
    }
    return 0;
}
