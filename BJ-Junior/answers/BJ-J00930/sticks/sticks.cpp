#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n == 1)cout<<-1<<endl;
        int n2 = n % 7;
        n /= 7;
        if(n2 == 0){
            for(int i = 1 ; i <= n ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 1){
            cout<<10;
            for(int i = 1 ; i < n ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 2){
            cout<<1;
            for(int i = 1 ; i <= n ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 3){
            cout<<200;
            for(int i = 1 ; i < n-1 ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 4){
            cout<<20;
            for(int i = 1 ; i < n ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 5){
            cout<<2;
            for(int i = 1 ; i <= n ; i++)cout<<8;
            cout<<endl;
        }
        if(n2 == 6){
            cout<<6;
            for(int i = 1 ; i <= n ; i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
