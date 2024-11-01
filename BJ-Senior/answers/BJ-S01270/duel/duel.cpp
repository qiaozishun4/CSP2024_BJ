#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long t,n,mii=1,cnt=0,a[200005];
bool b[200005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    a[0]=9e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>a[mii]){
            b[mii]=1;
            for(int j=mii;j<=n;j++){
                if(!b[j]){
                    mii=j;
                    break;
                }
            }
        }/*
        for(int i=1;i<=n;i++){
            cout<<b[i]<<endl;
        }*/
    }/*
    for(int i=1;i<=n;i++){
        cout<<b[i]<<endl;
    }*/
    for(int i=1;i<=n;i++){
        if(b[i])cnt++;
    }cout<<n-cnt<<endl;
    return 0;
}
