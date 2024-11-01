#include <bits/stdc++.h>
using namespace std;
int num[11],q;
// 0 1 2 4 6 7 8
// 6 2 5 4 6 3 7  (2~7)
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        if(n<2){cout<<-1<<endl;continue;}
        if(n%7==0){
            n/=7;
            for(int i=0;i<n;i++) cout<<8;
            cout<<endl;
        }
        else{
            int nl=n/7+1;
            int f=n%7;
            if(nl==1){
                if(n==2) cout<<1;
                if(n==3) cout<<7;
                if(n==4) cout<<4;
                if(n==5) cout<<2;
                if(n==6) cout<<6;
                cout<<endl;
            }
            else if(f==6){
                cout<<6;
                for(int i=0;i<nl-1;i++) cout<<8;
                cout<<endl;
            }
            else if(f==5){
                cout<<2;
                for(int i=0;i<nl-1;i++) cout<<8;
                cout<<endl;
            }
            else if(f==4){
                cout<<20;
                for(int i=0;i<nl-2;i++) cout<<8;
                cout<<endl;
            }
            else if(f==3){
                if(nl=2) cout<<22<<endl;
                else{
                    cout<<200;
                    for(int i=0;i<nl-3;i++) cout<<8;
                    cout<<endl;
                }
            }
            else if(f==2){
                cout<<1;
                for(int i=0;i<nl-1;i++) cout<<8;
                cout<<endl;
            }
            else if(f==1){
                cout<<10;
                for(int i=0;i<nl-2;i++) cout<<8;
                cout<<endl;
            }
        }
    }
    return 0;
}