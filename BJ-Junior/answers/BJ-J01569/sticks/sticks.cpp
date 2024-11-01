#include<bits/stdc++.h>
using namespace std;
int T,n;
int num[20]={-1,1,7,4,2,6,8,10,18,33,30,38,68,88,108,188,338,208,388,808};
int main(){
    freopen("sticks.in","r".stdin);
    freopen("sticks.out","w".stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=20){
            cout<<num[n]<<endl;
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else{
            cout<<n<<endl;
        }
    }
    return 0;
}
