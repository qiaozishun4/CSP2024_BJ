#include<bits/stdc++.h>
using namespace std;
int sticks[]={6,2,5,5,4,5,6,3,7,6};
int n;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=50){
        for(int i=pow(10,n/7+1);i<=1e7;i++){
            int sum=0;
            int temp=i;
            while(temp){
                sum+=sticks[temp%10];
                temp/=10;
            }
            if(sum==n){
                cout<<i<<endl;
            }
        }
        cout<<-1<<endl;
    }
    if(n%7==0){
        for(int i=1;i<=n/7;i++)cout<<8;cout<<endl;
    }
    if(n%7==1){
        cout<<10;
        for(int i=1;i<=n/7-1;i++)cout<<8;cout<<endl;
    }
    else cout<<-1<<endl;
    }
    return 0;
}
