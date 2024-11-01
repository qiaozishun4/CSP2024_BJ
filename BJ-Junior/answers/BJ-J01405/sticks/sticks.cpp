#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        if (n==1) cout<<-1<<endl;
        else if (n==2) cout<<1<<endl;
        else if (n==3) cout<<7<<endl;
        else if (n==4) cout<<4<<endl;
        else if (n==5) cout<<2<<endl;
        else if (n==6) cout<<6<<endl;
        else if (n==7) cout<<8<<endl;
        else if (n==8) cout<<10<<endl;
        else if (n==9) cout<<18<<endl;
        else if (n==10) cout<<22<<endl;
        else if (n%7==0){
            for (int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
        else if (n%7==1){
            cout<<"10";
            for (int i=1;i<=n/7-1;i++) cout<<"8";
            cout<<endl;
        }
        else if (n%7==2){
            cout<<"1";
            for (int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
        else if (n%7==3){
            cout<<"200";
            for (int i=1;i<=n/7-2;i++) cout<<"8";
            cout<<endl;
        }
        else if (n%7==4){
            cout<<"20";
            for (int i=1;i<=n/7-1;i++) cout<<"8";
            cout<<endl;
        }
        else if (n%7==5){
            cout<<"2";
            for (int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
        else{
            cout<<"6";
            for (int i=1;i<=n/7;i++) cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}