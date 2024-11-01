#include <iostream>
#include <cstdio>
using namespace std;
int n,t,f;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        f=0;
        cin>>n;
        if(n%7==1){
            f=1;
            n-=8;
        }
        while(n>0){
            cout<<8;
            n-=7;
        }
        if(f){
            cout<<0<<1;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
