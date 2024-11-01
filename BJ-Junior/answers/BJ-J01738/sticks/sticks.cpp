#include<bits/stdc++.h>
using namespace std;
int T,n,snum[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=(n/7);i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            n-=8;
            cout<<47;
            for(int i=1;i<=(n/7);i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        for(long long i=1;i<=1e18;i++){
            long long t=i,sum=0;
            while(t>0){
                sum+=snum[t%10];
                t/=10;
            }
            if(sum==n){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
