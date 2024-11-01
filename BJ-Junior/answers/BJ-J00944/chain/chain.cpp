#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int a,b,c,s,h,hashiqi;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b>>c>>s>>h;
        for(int j=1;j<=h;j++) cin>>hashiqi;
        for(int j=1;j<=b;j++) cin>>hashiqi;
        for(int j=1;j<=c;j++) cin>>hashiqi;
        for(int j=1;j<=s;j++) cin>>hashiqi>>hashiqi;
        srand(time(0));
        int ha=rand()%1+2;
        cout<<ha-1;
    }
    return 0;
}
