#include<bits/stdc++.h>
using namespace std;
int b[10]={0,16,18,22,20,28,68,88,10};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
        }
        else{
            cout<<b[n%7];
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}


