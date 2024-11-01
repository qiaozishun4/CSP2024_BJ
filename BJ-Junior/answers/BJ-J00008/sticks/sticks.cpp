#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int szh(int x){
    int sum=0;
    while(x){
        sum+=num[x%10];
        x/=10;
    }
    return sum;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1) cout<<-1;
        else if(n%7==0){
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else{
            for(int i=1;true;i++){
                if(szh(i)==n){cout<<i;break;}
            }
        }
        cout<<endl;
    }
    return 0;
}