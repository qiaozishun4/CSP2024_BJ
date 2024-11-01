#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n, sum=0, a=1, b;
        cin>>n;
        while(1){
            b=a;
            while(b>0){
                if(b%10==1){
                    sum+=2;
                }else if(b%10==7){
                    sum+=3;
                }else if(b%10==4){
                    sum+=4;
                }else if(b%10==3||b%10==2||b%10==5){
                    sum+=5;
                }else if(b%10==0||b%10==6||b%10==9){
                    sum+=6;
                }else if(b%10==8){
                    sum+=7;
                }
                b/=10;
            }
            if(sum==n){
                cout<<a;
                break;
            }
            if(sum>n*10){
                cout<<-1;
                break;
            }
            sum=0;
            a++;
        }
    }
    return 0;
}
