#include<bits/stdc++.h>
using namespace std;
int n,t,len,f[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1){
            cout<<"-1"<<endl;
            continue;
        }
        len=(n+6)/7;
        for(int i=1;i<=len;i++)
            for(int j=(i==1);j<=9;j++)
                if(((n-f[j])>=(len-i)*2)&&((n-f[j])<=(len-i)*7)){
                    n-=f[j];
                    cout<<j;
                    break;
                }
        cout<<endl;
    }
    return 0;
}
