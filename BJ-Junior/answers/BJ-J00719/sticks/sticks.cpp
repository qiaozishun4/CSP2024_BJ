#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[10]={-1,-1,1,7,4,2,6,8};
int main(){
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<7){
            cout<<a[n]<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }else if(n%7==1){
            cout<<"10";
            for(int i=1;i<=n/7-1;i++){
                cout<<'8';
            }

        }else if(n%7==2){
            cout<<"1";
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }else if(n%7==3){
            cout<<"22";
            for(int i=1;i<=n/7-1;i++){
                cout<<'8';
            }
        }else if(n%7==4){
            cout<<"20";
            for(int i=1;i<=n/7-1;i++){
                cout<<'8';
            }
        }else if(n%7==5){
            cout<<"2";
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }else{
            cout<<"6";
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }
        cout<<endl;
    }
    return 0;
}
