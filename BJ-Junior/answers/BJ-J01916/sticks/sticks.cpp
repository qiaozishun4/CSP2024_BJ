#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            n=n/7;
            for(int i=1;i<=n;i++){
                cout<<"8";

            }
            cout<<endl;
            continue;
        }
        if((n-1)%7==0){
            n=n/7;
            cout<<"1";
            for(int i=1;i<=n;i++){
                cout<<"8";
            }
            cout<<endl;
            continue;
        }

    }

    return 0;
}
