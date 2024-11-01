#include<bits/stdc++.h>
using namespace std;
int T,n;
int f[25]={-1,-1,1,7,4,2,6,8,10,24,22,20,28,80};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=13){
            cout<<f[n]<<endl;
            continue;
        }
        int num=n%7+7;
        cout<<f[num];
        for(int i=1;i<=n/7-1;i++){
            cout<<8;
        }
        cout<<endl;
    }
}

