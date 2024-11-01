#include <bits/stdc++.h>

using namespace std;
int t,n,a[21]={0,-1,1,7,4,2,6,8,10,17,22,26,28,68,88,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++)
                cout <<8;
            cout <<endl;
        }
        else if(n==1)
            cout <<-1<<endl;
        else if(n<=20)
            cout <<a[n]<<endl;
        else if(n%7==1){
            cout <<10;
            for(int i=1;i<=n/7-1;i++)
                cout <<8;
            cout <<endl;
        }
    }
    return 0;
}
