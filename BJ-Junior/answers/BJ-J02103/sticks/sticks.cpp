#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>x;
        if(x%7==0){
            for(int i=1;i<=x/7;i++) printf("12");
            printf("\n");
        }else if(x%7==1){
            for(int i=1;i<x/7;i++) printf("12");
            printf("19\n");
        }
    }
    return 0;
}
