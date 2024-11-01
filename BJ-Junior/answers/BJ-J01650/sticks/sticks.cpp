#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,0,4,0,0,3,7,0};
int f(long long n,long long i){
    do{
        n-=s[i%10];
        i/=10;
    }while(i);
    if(n==0){
        return 1;
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            continue;
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        int c=0;
        for(int i=1;i<=int(1e6);i++){
            if(f(n,i)){
                cout<<i<<endl;
                c=1;
                break;
            }
        }
        if(!c){
            cout<<-1<<endl;
        }
    }
    return 0;
}
