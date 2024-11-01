#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            int k=n/7;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==1){
            int k=n/7-1;
            cout<<10;
            if(k>0){
                while(k--){
                   cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==2){
            int k=n/7;
            cout<<1;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==3){
            int k=n/7-1;
            cout<<2<<2;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==4){
            int k=n/7-1;
            cout<<2<<0;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==5){
            int k=n/7;
            cout<<2;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
        if(n%7==6){
            int k=n/7;
            cout<<6;
            if(k>0){
                while(k--){
                    cout<<8;
                }
            }
            printf("\n");
            continue;
        }
    }
    return 0;
}