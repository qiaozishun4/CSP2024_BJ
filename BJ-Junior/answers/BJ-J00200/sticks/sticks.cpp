#include <bits/stdc++.h>
using namespace std;
int r[9998];
int s[9997];
int main(){
    int t,n,p,h;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        int W=0,e=1;
        cin>>t;
        if(t<=1){
            cout<<-1<<endl;
            continue;
        }
        p=t%7;
        h=t/7;
        for(int i=1;i<=h;i++){
            r[i]=7;
        }
        if(p==0){
            while(h--){
                W+=e*8;
                e*=10;
            }
            cout<<W<<endl;
            continue;
        }
        else if(p==1){
            r[h+1]=2;
            r[h]-=1;
        }
        else if(p==2 or p==5){
            r[h+1]=p;
        }
        else if(p==3){
            r[h+1]=5;
            r[h]-=1;
            r[h-1]-=1;
        }
        else if(p==4){
            r[h+1]=5;
            r[h]-=1;
        }
        else{
            r[h+1]=6;
        }
        for(int i=1;i<=h+1;i++){
            if(r[i]==2){
                s[i]=1;
            }
            else if(r[i]==5){
                s[i]=2;
            }
            else if(r[i]==6){
                if(p==6){
                    s[i]=6;
                }
                else{
                    s[i]=0;
                }
            }
            else if(r[i]==7){
                s[i]=8;
            }
            else{
                s[i]=0;
            }
        }
        for(int i=1;i<=h+1;i++){
            W+=e*s[i];
            e*=10;
        }
        cout<<W<<endl;
    }
    return 0;
}