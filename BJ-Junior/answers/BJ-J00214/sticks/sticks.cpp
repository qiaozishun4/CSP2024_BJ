#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int num=n/7;
        n=n%7;
        if(n==0){
            if(num==0)cout<<-1;
            else for(int i=1;i<=num;i++)cout<<"8";
            cout<<endl;
        }
        else if(n==1){
            if(num==0)cout<<-1;
            else{
                cout<<"10";
                for(int i=1;i<num;i++)cout<<"8";
            }
            cout<<endl;
        }
        else if(n==2){
            cout<<"1";
            for(int i=1;i<=num;i++)cout<<"8";
            cout<<endl;
        }
        else if(n==3){
            if(num>=2){
                cout<<"200";
                for(int i=1;i<num-1;i++)cout<<"8";
            }
            else if(num>=1){
                cout<<"40";
                for(int i=1;i<num;i++)cout<<"8";
            }
            else {
                cout<<"7";
                for(int i=1;i<=num;i++)cout<<"8";
            }
            cout<<endl;
        }
        else if(n==4){
            if(num>=1){
                cout<<"20";
                for(int i=1;i<num;i++)cout<<"8";
            }else {
                cout<<"4";
                for(int i=1;i<=num;i++)cout<<"8";
            }
            cout<<endl;
        }
        else if(n==5){
            cout<<"2";
            for(int i=1;i<=num;i++)cout<<"8";
            cout<<endl;
        }
        else if(n==6){
            cout<<"6";
            for(int i=1;i<=num;i++)cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}
