#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int main(){
    //6 2 5 5 4 5 6 3 7 6
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        x=n/7;
        if(n%7==0)
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        else if(n%7==1 && n!=1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }
        else if(n%7==3){
            if(x>=1){
                x--;
                cout<<2;
            }
            else cout<<7;
            for(int i=1;i<=n/7-x;i++){
                cout<<2;
            }
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }
        else if(n%7==4){
            if(x>=1){
                x--;
                cout<<2;
            }
            else cout<<4;
            for(int i=1;i<=n/7-x;i++){
                cout<<0;
            }
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
