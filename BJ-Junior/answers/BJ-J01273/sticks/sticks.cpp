#include<bits/stdc++.h>
using namespace std;
int out8(int t){
    for(int i=0;i<t;i++){
        cout<< '8';
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        if(t%7==0)out8(t/7);
        else if(t%7==2){
            cout<<"24";
            out8((t-9)/7);
        }
        else if(t%7==3){
            cout<<"22";
            out8((t-10)/7;
        }
        else if(t%7==4){
            cout<<"20";
            out8((t-11)/7);
        }
        else if(t%7==5){
            cout<<"60";
            out8((t-12)/7);
        }
        else if(t%7==6){
            cout<<"80";
            out8((t-9)/7);
        }
        else {
            cout<<"10";
            out8((t-8)/7);
        }
        cout<<endl;
    }
    return 0;
}


