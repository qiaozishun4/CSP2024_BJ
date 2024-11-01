#include <bits/stdc++.h>
using namespace std;
void MAIN(){
    int n;
    cin>>n;
    if (n%7==0){
        for (int i=1;i<=n/7;i++) cout<<8;
        cout<<endl;
    }
    else if ((n-1)%7==0 && n>=100){
        cout<<16;
        for (int i=1;i<=(n-8)/7;i++) cout<<8;
        cout<<endl;
    }
    else cout<<-1<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}
