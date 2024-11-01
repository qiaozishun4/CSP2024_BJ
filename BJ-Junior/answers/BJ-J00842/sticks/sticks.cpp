#include<bits/stdc++.h>
using namespace std;
int T,num[55],ans[15] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i = 0;i<T;i++){
        cin>>num[i];
        if(num[i]<=14){
            cout<<ans[num[i]]<<endl;
        }
        else if(num[i]%7==0){
            for(int j = 0;j<num[i]/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(num[i]%7==1){
            cout<<10;
            for(int j = 0;j<(num[i]-8)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
        else if(num[i]%7==2){
            cout<<1;
            for(int j = 0;j<(num[i]-2)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
        else if(num[i]%7==3){
            cout<<200;
            for(int j = 0;j<(num[i]-17)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
        else if(num[i]%7==4){
            cout<<20;
            for(int j = 0;j<(num[i]-11)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
        else if(num[i]%7==5){
            cout<<2;
            for(int j = 0;j<(num[i]-5)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
        else if(num[i]%7==6){
            cout<<6;
            for(int j = 0;j<(num[i]-6)/7;j++){
                cout<<8;
            }
        cout<<endl;
        }
    }
    return 0;
}

