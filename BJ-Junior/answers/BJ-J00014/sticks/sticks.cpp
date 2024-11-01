#include<bits/stdc++.h>
using namespace std;
int mins(int x){
    if(x<2)return -1;
    if(x==2)return 1;
    if(x==3)return 7;
    if(x==4)return 4;
    if(x==5)return 2;
    if(x==6)return 6;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n/7){
            if(n%7==0){
                cout<<string(n/7,'8')+"\n";
                continue;
            }
            if(n%7==1){
                cout<<"10"+string(n/7-1,'8')+"\n";
                continue;
            }
            if(n%7==2){
                cout<<"1"+string(n/7,'8')+"\n";
                continue;
            } 
            if(n==10){
                cout<<22<<endl;
                continue;
            }
            if(n%7==3){
                cout<<"200"+string(n/7-2,'8')+"\n";
                continue;
            }
            if(n%7==4){
                cout<<"20"+string(n/7-1,'8')+"\n";
                continue;
            }
            if(n%7==5){
                cout<<"2"+string(n/7,'8')+"\n";
                continue;
            }
            if(n%7==6){
                cout<<"6"+string(n/7,'8')+"\n";
                continue;
            }
        }
        else{
            cout<<mins(n)<<endl;
        }
    }
    return 0;
}