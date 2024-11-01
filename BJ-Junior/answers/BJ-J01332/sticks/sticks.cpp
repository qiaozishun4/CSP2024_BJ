#include <bits/stdc++.h>
using namespace std;
long long n,x;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>=6){
            cout<<"0"<<endl;
        }
        else if(x>=2){
            cout<<"1"<<endl;
        }
        else if(x>=5){
            cout<<"2"<<endl;
        }
        else if(x>=4){
            cout<<"4"<<endl;
        }
        else if(x>=3){
            cout<<"7"<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
