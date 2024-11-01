#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,4,6,2,7};
int ss[10]={0,1,2,4,6,7,8};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0||n<=20){
            if(n%7==0){
                for(int i=1;i<=n/7;i++) cout<<8;
            }
            else if(n==1) cout<<-1;
            else if(n==2) cout<<1;
            else if(n==3) cout<<7;
            else if(n==4) cout<<4;
            else if(n==5) cout<<2;
            else if(n==6) cout<<6;
            else if(n==8) cout<<10;
            else if(n==9) cout<<16;
            else if(n==10) cout<<22;
            else if(n==11) cout<<106;
            else if(n==12) cout<<104;
            else if(n==13) cout<<102;
            else if(n==14) cout<<106;
            else if(n==15) cout<<108;
            if(t!=0) cout<<endl;
            continue;
        }
    }
    return 0;
}