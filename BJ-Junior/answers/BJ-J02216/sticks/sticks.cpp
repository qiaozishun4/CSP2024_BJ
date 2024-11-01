#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i=n;
        if(n%7==0){
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1){
            if(n==1){
                cout<<-1<<endl;
                continue;
            }
            cout<<10;
            i-=8;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==2){
            cout<<1;
            i-=2;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==3){
            if(n==3){
                cout<<7<<endl;
                continue;
            }
            cout<<23;
            i-=10;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==4){
            if(n==4){
                cout<<4<<endl;
                continue;
            }
            cout<<20;
            i-=11;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==5){
            cout<<2;
            i-=5;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==6){
            cout<<6;
            i-=6;
            for(;i>0;i-=7){
                cout<<8;
            }
            cout<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
