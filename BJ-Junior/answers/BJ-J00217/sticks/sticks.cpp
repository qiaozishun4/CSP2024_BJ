#include<bits/stdc++.h>
using namespace std;
int l[13]={-1,1,7,4,2,6,8,10,18,23,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n;
        if(n<=13){
            cout<<l[n-1]<<endl;
            continue;
        }
        cout<<l[n%7+7-1];
        for(int i=0;i<n/7-1;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
