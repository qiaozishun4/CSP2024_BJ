#include<bits/stdc++.h>
using namespace std;
long long t,f[100010],l=7;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    f[1]=-1;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=0;
    f[7]=8;
    for(int h=1;h<=t;h++){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1 && n!=1){
            cout<<10;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n==6){
            cout<<6<<endl;
        }else if(n<=l){
            cout<<f[n]<<endl;
        }else{
            while(l<n){
                l++;
                long long ans=1e9;
                for(int j=2;j<=7;j++){
                    if(l-j==1){
                        continue;
                    }
                    if(l-j==6){
                        ans=min(ans,60+f[j]);
                    }else{
                        ans=min(ans,f[l-j]*10+f[j]);
                    }
                }
                f[l]=ans;
            }
            cout<<f[n]<<endl;
        }
    }
    return 0;
}
