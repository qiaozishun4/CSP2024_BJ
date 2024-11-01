#include <cstdio>
#include <iostream>
using namespace std;
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        n/=7;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
