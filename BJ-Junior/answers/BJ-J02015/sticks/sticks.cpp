#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int m=(n+6)/7;
        if(n%7==0){
            for(int i=1;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==1&&m>=2){
            cout<<"16";
            for(int i=3;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==2&&m>=1){
            cout<<"1";
            for(int i=2;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==3&&m>=3){
            cout<<"200";
            for(int i=4;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==4&&m>=2){
            cout<<"20";
            for(int i=3;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==5&&m>=1){
            cout<<"2";
            for(int i=2;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else if(n%7==6&&m>=1){
            cout<<"6";
            for(int i=2;i<=m;i++) cout<<"8";
            cout<<'\n';
        }else{
            if(n==3) cout<<"7\n";
            else if(n==4) cout<<"4\n";
            else if(n==10) cout<<"22\n";
            else cout<<"-1\n";
        }
    }
    return 0;
}
