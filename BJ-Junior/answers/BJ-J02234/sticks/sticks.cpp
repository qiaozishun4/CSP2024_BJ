#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t,n;
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>n;
        if(n%7==0){
            for(int p=1;7*p<=n;p++){
                cout<<'8';
            }
            cout<<endl;
        }
        else if(n%6==0){
            cout<<'6';
            for(int p=1;6*p+6<=n;p++){
                cout<<'0';
            }
            cout<<endl;
        }
        else{
            cout<<"-1\n";
        }
    }
}
