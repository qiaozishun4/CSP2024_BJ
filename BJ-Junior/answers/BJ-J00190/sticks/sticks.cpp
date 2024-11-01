#include <bits/stdc++.h>
using namespace std;
long long n,t,cnt;
long long b[22]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cnt=0;
        while(n>21){
            n-=7;
            cnt++;
        }
        cout<<b[n];
        for(long long i=1;i<=cnt;i++){
            cout<<8;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
