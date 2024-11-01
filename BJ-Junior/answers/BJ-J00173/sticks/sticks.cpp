#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long n;
    cin>>n;
    while(n!=0){
        n--;
        //cout<<1;
        int s;
        cin>>s;
        if(s==1){
            cout<<-1;
            continue;
        }
        if(s==2){
            cout<<1;
            continue;
        }
        int i=0;
        bool f=0;
        while(true){
            i++;
            int m=i,t=0,sum=0;
            while(m!=0){
                t=m%10;
                if(t==0) sum+=6;
                if(t==1) sum+=2;
                if(t==2) sum+=5;
                if(t==3) sum+=5;
                if(t==4) sum+=4;
                if(t==5) sum+=5;
                if(t==6) sum+=6;
                if(t==7) sum+=3;
                if(t==8) sum+=7;
                if(t==9) sum+=6;
                m/=10;
            }
            //cout<<1;
            //cout<<sum<<endl;
            if(sum==s){
                cout<<i<<endl;
                f=1;
                break;
            }
            if(i>10000){
                break;
            }
        }
        if(f==0) cout<<-1;
    }
    return 0;
}
