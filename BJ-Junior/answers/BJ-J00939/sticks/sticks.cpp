#include<iostream>
#include<cstdio>
using namespace std;
int t,n,f[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1) cout << -1<<endl;
        else if(n%7==1){
            cout<<10;
            for(int i = 1;i < n/7;i++) cout <<8;
            cout << endl;
        }
        else if(n%7==0){
            for(int i = 1;i <= n/7;i++) cout <<8;
            cout << endl;
        }
        else if(n%7==2){
            cout<<1;
            for(int i = 1;i <= n/7;i++) cout <<8;
            cout << endl;
        }
        else if(n%7==3){
            if(n==3)cout<<7<<endl;
            else if(n==10)cout<<40<<endl;
            else{
                cout<<200;
                for(int i = 1;i <= n/7-2;i++) cout <<8;
                cout << endl;
            }
        }
        else if(n%7==4){
            if(n==4)cout<<4<<endl;
            else if(n==11)cout<<20<<endl;
            else{
                cout<<20;
                for(int i = 1;i <= n/7-1;i++) cout <<8;
                cout << endl;
            }
        }
        else if(n%7==5){
            cout<<2;
            for(int i = 1;i <= n/7;i++) cout <<8;
            cout << endl;
        }
        else{
            cout<<6;
            for(int i = 1;i <= n/7;i++) cout <<8;
            cout << endl;
        }
    }
    return 0;
}
