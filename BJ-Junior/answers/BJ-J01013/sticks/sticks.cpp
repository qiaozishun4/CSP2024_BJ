#include<bits/stdc++.h>
using namespace std;
int main(){
    int q[25]={-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
    int a,s,d;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>s;
        if(s<=21){
            cout<<q[s-1]<<endl;
        }else{
            if(s%7==0){
                for(int j=1;j<=s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==1){
                cout<<10;
                for(int j=1;j<s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==2){
                cout<<1;
                for(int j=1;j<=s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==3){
                cout<<200;
                for(int j=2;j<s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==4){
                cout<<20;
                for(int j=1;j<s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==5){
                cout<<2;
                for(int j=1;j<=s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }else if(s%7==6){
                cout<<6;
                for(int j=1;j<=s/7;j++){
                    cout<<8;
                }
                cout<<endl;
            }
        }

    }
    return 0;
}