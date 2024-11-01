#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<"16";
            for(int i=1;i<=(n-8)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%7==2){
            cout<<'1';
            for(int i=1;i<=(n-2)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%7==3){
            cout<<'7';
            for(int i=1;i<=(n-3)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%7==4){
            if(n==4){
                cout<<4<<endl;
                continue;
            }
            cout<<"20";
            for(int i=1;i<=(n-11)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%7==5){
            cout<<'5';
            for(int i=1;i<=(n-5)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
        else{
            cout<<'6';
            for(int i=1;i<=(n-6)/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}