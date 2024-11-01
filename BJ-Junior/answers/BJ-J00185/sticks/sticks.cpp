#include <bits/stdc++.h>
using namespace std;
int y[10]={6,2,5,5,4,5,6,3,7,6};
long long n;
int sum(int a){

    int stk=0;
    int tmp=a;
    while(a>=10){
        stk+=y[a%10];
        a=a/10;
    }
    stk+=y[a];
    a=tmp;
    return stk;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    int x[n];

    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int flag=0;
    for(int i=0;i<n;i++){
        flag=0;
        if(x[i]>50){
            if(x[i]%7==0){
                for(int j=0;j<x[i]/7;j++){
                    cout<<8;
                }
                cout<<endl;
                flag=1;
            }else if(x[i]%7==1){
                cout<<16;
                for(int j=0;j<(x[i]-8)/7;j++){
                    cout<<8;
                }
                cout<<endl;
                flag=1;
            }
        }

        for(int a=1;a<10000000;a++){
            if(sum(a)==x[i]){
                cout<<a<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<-1<<endl;
        }

    }

    return 0;

}
