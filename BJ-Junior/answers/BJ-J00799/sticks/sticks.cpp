#include<bits/stdc++.h>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<"10";
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        int f=0;
        for(int i=1;i<=1600000;i++){
            int x=i;
            int cnt=0;
            while(x){
                cnt+=a[x%10];
                x/=10;
            }
            if(cnt==n){
                f=1;
                cout<<i<<endl;
                break;
            }
        }
        if(!f){
            cout<<-1<<endl;
        }
    }
    return 0;
}
