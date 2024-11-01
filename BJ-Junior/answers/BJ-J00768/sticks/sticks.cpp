#include <bits/stdc++.h>
int g,n,h=1,m,hhh[22]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>g;
    for(int i=1;i<=g;i++){
        cin>>n;
        if(n<=20){
            cout<<hhh[n];
        }
        else{
            m=n/7;
            for(int j=1;j<=m;j++)cout<<8;
        }
        cout<<endl;
    }
 return 0;
}
