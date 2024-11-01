#include <bits/stdc++.h>
using namespace std;
long long t,n;
int d[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1)cout<<-1;
        else if(n%7==0){
            for(int i=0;i<n/7;i++){
                cout<<'8';
            }
        }else if(n%7==1){
            cout<<"10";
            for(int i=0;i<(n-8)/7;i++){
                cout<<'8';
            }
        }else if(n%7==2){
            cout<<'1';
            for(int i=0;i<(n-2)/7;i++){
                cout<<'8';
            }
        }else if(n%7==3){
            if(n==3)cout<<'7';
            else{
                cout<<"22";
                for(int i=0;i<(n-10)/7;i++){
                    cout<<'8';
                }
            }
        }else if(n%7==4){
            if(n==3)cout<<'4';
            else{
                cout<<"20";
                for(int i=0;i<(n-11)/7;i++){
                    cout<<'8';
                }
            }
        }else if(n%7==5){
            if(n==5)cout<<'2';
            else{
                cout<<"2";
                for(int i=0;i<(n-11)/7;i++){
                    cout<<'8';
                }
            }
        }else if(n%7==6){
            if(n==6)cout<<'6';
            else{
                cout<<"6";
                for(int i=0;i<(n-11)/7;i++){
                    cout<<'8';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
