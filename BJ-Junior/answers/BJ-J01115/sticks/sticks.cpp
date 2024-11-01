hello world
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>m;
        if(m%7 == 0){
            for(int j = 1;j <= m/7;j++){
                cout<<"8";
            }
            cout<<endl;
        }
        if(m%7 == 1){
            cout<<"10";
            for(int j = 1;j <= m/7-1;j++){
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}
