#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long f[N];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            int y=n/7;
            for(int i=1;i<=y;i++){
                printf("8");
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            int y=(n-8)/7;
            cout<<1<<0;
            for(int i=1;i<=y;i++){
                printf("8");
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
