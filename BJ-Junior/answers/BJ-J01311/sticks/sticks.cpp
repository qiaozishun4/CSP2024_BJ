#include<bits/stdc++.h>
using namespace std;
bool flag=false;
int ff(int a){
    if(a==0) return 6;
    if(a==1) return 2;
    if(a==2) return 5;
    if(a==3) return 5;
    if(a==4) return 4;
    if(a==5) return 5;
    if(a==6) return 6;
    if(a==7) return 3;
    if(a==8) return 7;
    if(a==9) return 6;
}
int gg(int a){
    if(a==6) return 0;
    if(a==2) return 1;
    if(a==5) return 2;
    if(a==4) return 4;
    if(a==3) return 7;
    if(a==7) return 8;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<1<<0;
            for(int j=1;j<=(n-8)/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            int p=ceil(1.0*n/7);
            int m=n;
            for(int j=1;j<=p;j++){
                for(int l=0;l<=9;l++){
                        if(gg(m)<=8){
                        if(gg(m)==0 && flag==false)cout<<6;
                        else cout<<gg(m);
                        break;
                        }
                    else if((m-ff(l))<=((p-1)*7)){
                        if(l==0 && flag==false) continue;
                        else cout<<l;
                        flag=true;
                        m=m-ff(l);
                        break;
                    }
                }
            }
            cout<<endl;
            flag=false;
        }
    }
    return 0;
}

