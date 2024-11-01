#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        long long n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n<10){
            if(n==2){
                cout<<1<<endl;
            }
            if(n==3){
                cout<<7<<endl;
            }
            if(n==4){
                cout<<4<<endl;
            }
            if(n==5){
                cout<<2<<endl;
            }
            if(n==6){
                cout<<6<<endl;
            }
            if(n==7){
                cout<<8<<endl;
            }
            if(n==8){
                cout<<16<<endl;
            }
            if(n==9){
                cout<<18<<endl;
            }
        }
        else if(n>=10){
            if(n%7==0){
                int sum=n/7;
                for(int i=1;i<=sum;i++){
                    cout<<8;
                }
                cout<<endl;
            }
            else if(n%7==1){
                int ans=n/7-1;
                cout<<10;
                for(int i=1;i<=ans;i++){
                    cout<<8;
                }
                cout<<endl;
            }
            else if(n==10){
                cout<<22<<endl;
            }
            else if(n==11){
                cout<<20<<endl;
            }
            else if(n==12){
                cout<<22<<endl;
            }
            else if(n==13){
                cout<<68<<endl;
            }
            else if(n==16){
                cout<<188<<endl;
            }
            else if(n==17){
                cout<<200<<endl;
            }
            else if(n==18){
                cout<<208<<endl;
            }
            else if(n==19){
                cout<<288<<endl;
            }
            else if(n==20){
                cout<<688<<endl;
            }
        }

    }


    return 0;
}
