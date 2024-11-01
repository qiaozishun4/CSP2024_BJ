#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        if(n<2){
            cout<<"-1"<<endl;
            continue;
        }
        else if(n%7==0){
            int x=n/7;
            for(int i=1;i<=x;i++){
                cout<<"8";
            }
            cout<<endl;
            continue;
        }
        else if(n==2){
            cout<<"1"<<endl;
            continue;
        }
        else if(n==3){
            cout<<"7"<<endl;
            continue;
        }
        else if(n==4){
            cout<<"4"<<endl;
            continue;
        }
        else if(n==5){
            cout<<"2"<<endl;
            continue;
        }
        else if(n==6){
            cout<<"6"<<endl;
            continue;
        }
        else if(n%6==2){
            int x=n/6;
            cout<<"1";
            for(int i=1;i<=x;i++) cout<<"0";
            cout<<endl;
            continue;
        }
        else if(n%2){
            cout<<"2";
            n-=5;
        }
        int x=n/2;
        if(x%3==1){
            cout<<"1";
            x--;
        }
        int y=n/12;
        for(int i=1;i<=y;i++) cout<<"2";
        x%=6;
        bool flag=0;
        if(x%3==2){
            flag=1;
            x-=2;
        }
        while(x){
            if(x!=n/2) cout<<"0";
            else cout<<"6";
            x-=3;
        }
        if(flag){
            cout<<"4";
        }
        for(int i=1;i<=y;i++) cout<<"8";
        cout<<endl;
    }

    return 0;
}
