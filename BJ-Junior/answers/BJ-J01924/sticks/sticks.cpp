#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> p;
void pf(int n,int ws,int ys){
    if(ys==0){
        for(int i=1;i<=ws;i++){
            cout<<8;
        }
        return;
    }
    if(ws>2){
        if(ys<=2){
            cout<<1;
            ys=7-(2-ys);
        }else if(ys<=5){
            cout<<2;
            ys=7-(5-ys);
        }else if(ys<=6){
            cout<<6;
            ys=7-(6-ys);
        }
        for(int i=ws;i>=2;i--){
            if(i>2){
                if(ys<=2){
                    cout<<1;
                    ys=7-(2-ys);
                }else if(ys<=5){
                    cout<<2;
                    ys=7-(5-ys);
                }else if(ys<=6){
                    cout<<0;
                    ys=7-(6-ys);
                }else{
                    cout<<8;
                }
            }else if(i==2){
                if(ys<=2){
                    cout<<1;
                    ys=7-(2-ys);
                    cout<<p[ys]<<"\n";
                }else if(ys<=5){
                    cout<<2;
                    ys=7-(5-ys);
                    cout<<p[ys]<<"\n";
                }else if(ys<=6){
                    cout<<6;
                    ys=7-(6-ys);
                    cout<<p[ys]<<"\n";
                }else{
                    cout<<8<<"\n";
                }
            }
        }
    }else if(ws==2){
        if(ys<=2){
            cout<<1;
            ys=7-(2-ys);
            cout<<p[ys]<<"\n";
        }else if(ys<=5){
            cout<<2;
            ys=7-(5-ys);
            cout<<p[ys]<<"\n";
        }else if(ys<=6){
            cout<<6;
            ys=7-(6-ys);
            cout<<p[ys]<<"\n";
        }
    }else{
        p[6]=6;
        cout<<p[n]<<"\n";
        p[6]=0;
    }

    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    p[2]=1;
    p[3]=7;
    p[4]=4;
    p[5]=2;
    p[6]=0;
    p[7]=8;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int m=ceil(n*1.0/7),k=n%7;
        if(n==0 || n==1) {
           cout<<-1;
           continue;
        }
        pf(n,m,k);
    }
    return 0;
}
