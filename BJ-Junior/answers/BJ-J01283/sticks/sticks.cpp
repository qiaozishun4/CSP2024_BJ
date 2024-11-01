#include<bits/stdc++.h>
using namespace std;
long long jisuan(long long n){
    if(n==1)return -1;
    else if(n==2)return 1;
    else if(n==3)return 7;
    else if(n==4)return 4;
    else if(n==5)return 2;
    else if(n==6)return 6;
    else if(n==7)return 8;
    else if(n==8)return 10;
    else if(n==9)return 18;
    else if(n==10)return 22;
    else if(n==11)return 20;
    else if(n==12)return 28;
    else if(n==13)return 80;
    else if(n==14)return 88;
    else if(n==15)return 100;
    else if(n==16)return 188;
    else if(n==17)return 200;
    else if(n==18)return 208;
    else if(n==19)return 288;
    else if(n==20)return 808;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin>>t;
    long long n[t];
    for(long long i=0;i<t;i++){
        cin>>n[i];
    }
    long long i=0;
    for(long long i=0;i<t;i++){
        if(n[i]%7==0){
            long long p=n[i]/7;
            string s;
            for(long long i=0;i<p;i++){
                s+="8";
            }
            cout<<s;
        }
        else{
            cout<<jisuan(n[i])<<endl;
        }
    }
    return 0;
}
