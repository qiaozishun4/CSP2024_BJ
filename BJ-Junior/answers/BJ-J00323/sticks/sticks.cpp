#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
int a[22]={-1,-1,1,7,4,2,6,8,10,18,22,20,58,80,88,100,188,206,208,888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=20) cout<<a[n]<<endl;
        else if(n%7==0){
            for(int i=0;i<=n/7;i++){
                cout<<0<<endl;
            }
        }else{
            cout<<10;
            for(int i=1;i+1<=n/7;i++) cout<<0<<endl;
        }
    }
    return 0;
}

