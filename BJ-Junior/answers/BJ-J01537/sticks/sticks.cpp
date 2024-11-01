#include<bits/stdc++.h>
using namespace std;
int a[]={-1,-1,1,7,4,2,6,8};//0:6 1:2 2:5 3:5 4:4 5:5 6:6 7:3 8:7 9:6
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=7){
            cout<<a[n];
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        else if((n-1)%7==0){
            cout<<1;
            for(int i=1;i<=(n-1)/7;i++){
                if(i==1){
                    cout<<0;
                }
                else{
                    cout<<8;
                }
            }
        }
        else if((n-2)%7==0){
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
        }
        else if((n-3)%7==0){
            cout<<2;
            for(int i=1;i<=(n-3)/7;i++){
                if(i==1){
                    cout<<2;
                }
                else
                cout<<8;
            }
        }
        else if((n-4)%7==0){
            cout<<2;
            for(int i=1;i<=(n-4)/7;i++){
                if(i==1){
                    cout<<0;
                }
                else{
                    cout<<8;
                }
            }
        }
        else if((n-5)%7==0){
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++){
                cout<<8;
            }
        }
        else if((n-6)/7==0){
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++){
                cout<<8;
            }
        }
        cout<<'\n';
    }
    return 0;
}
