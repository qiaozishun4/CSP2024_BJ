#include<bits/stdc++.h>
using namespace std;
int x[15]={6,2,5,5,4,5,6,3,7,6};
long long f(long long n){
    int sum=0;
    while(n>0){
        if(n%10==0){
            sum+=6;
        }else if(n%10==1){
            sum+=2;
        }else if(n%10==2){
            sum+=5;
        }else if(n%10==3){
            sum+=5;
        }else if(n%10==4){
            sum+=4;
        }else if(n%10==5){
            sum+=5;
        }else if(n%10==6){
            sum+=6;
        }else if(n%10==7){
            sum+=3;
        }else if(n%10==8){
            sum+=7;
        }else if(n%10==9){
            sum+=6;
        }
        n=n/10;
    }
    return sum;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long n,a;
    cin>>n;
    for(long long j=1;j<=n;j++){
        cin>>a;
        for(long long i=1;i<=10000;i++){
            if(a==1){
                cout<<"-1"<<endl;
                break;
            }
            long long re=f(i);
            if(re==a){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
