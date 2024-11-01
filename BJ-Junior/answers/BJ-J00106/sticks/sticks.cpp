#include <bits/stdc++.h>
using namespace std;
int t;
int s[20]={6,2,5,5,4,5,6,3,7,6};
int minn[20]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        int n;
        cin>>n;
        if(n<=14){
            cout<<minn[n]<<endl;
        }else{
            if(n%7==1){
                n-=8;
                cout<<10;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==2){
                n-=2;
                cout<<1;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==3){
                n-=17;
                cout<<200;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==4){
                n-=11;
                cout<<20;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==5){
                n-=5;
                cout<<2;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==6){
                n-=6;
                cout<<6;
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            if(n%7==0){
                while(n>0){
                    n-=7;
                    cout<<8;
                }
                cout<<endl;
            }
        }
    }

    return 0;
}
