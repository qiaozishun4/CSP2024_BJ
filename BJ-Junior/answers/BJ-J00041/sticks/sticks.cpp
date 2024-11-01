#include<bits/stdc++.h>
using namespace std;
int t;
int a[10];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    for(long long i=1;i<=t;i++){
        int n;
        long long x=0,y=0;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<10;
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            for(long long j=1;j<=n/2+n%2;j++){
                x=x*10+1;
            }
            for(long long j=1;j<=x;j++){
                for(long long l=j;l!=0;l/=10){
                    y+=a[l%10];
                }
                if(y==n){
                    cout<<j<<endl;
                    break;
                }
                y=0;
            }
        }
    }
    return 0;
}
