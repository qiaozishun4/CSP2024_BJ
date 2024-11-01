#include<bits/stdc++.h>
using namespace std;
int T,n;
int tms,yu;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.in","w",stdout);
    cin>>T;
    for(int t=1;t<=T;++t){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==3){
            cout<<7<<endl;
            continue;
        }
        if(n==4){
            cout<<4<<endl;
            continue;
        }
        if(n%7==0){
            tms=n/7;
            yu=0;
            for(int i=1;i<=tms;++i){
                cout<<8;
            }
        }else{
            tms=n/7+1;
            yu=n-(tms-1)*7;
            if(yu==1){
                cout<<10;
                for(int i=1;i<tms-1;++i){
                    cout<<8;
                }
            }else if(yu==2){
                cout<<1;
                for(int i=1;i<tms;++i){
                    cout<<8;
                }
            }else if(yu==3){
                cout<<40;
                for(int i=1;i<tms-1;++i){
                    cout<<8;
                }
            }else if(yu==4){
                cout<<20;
                for(int i=1;i<tms-1;++i){
                    cout<<8;
                }
            }else if(yu==5){
                cout<<2;
                for(int i=1;i<tms;++i){
                    cout<<8;
                }
            }else if(yu==6){
                cout<<6;
                for(int i=1;i<tms;++i){
                    cout<<8;
                }
            }
        }
        cout<<endl;
    }
}
