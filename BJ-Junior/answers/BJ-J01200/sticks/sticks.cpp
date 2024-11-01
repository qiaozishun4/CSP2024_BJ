#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f(int n){
    if(n<2) return -1;
    for(ll i=1;i<=1000000000;i++){
        int sum=0,k=i;
        while(k>0){
            if(k%10==1) sum+=2;
            else if(k%10==7) sum+=3;
            else if(k%10==4) sum+=4;
            else if(k%10==2||k%10==3||k%10==5) sum+=5;
            else if(k%10==0||k%10==6||k%10==9) sum+=6;
            else if(k%10==8) sum+=7;
            k/=10;
        }
        if(sum==n) return i;
    }
    return -1;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<t;i++){
        cout<<f(a[i])<<"\n";
    }
    return 0;
}
