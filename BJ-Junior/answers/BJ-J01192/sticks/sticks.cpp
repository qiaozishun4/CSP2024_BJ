#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("sticks.in","r",stdin);
    //freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        int n;
        cin>>n;
        if(n%7==0){
            n/=7;
            for(int j=1;j<=n;++j){
                cout<<'8';
            }
            cout<<'\n';
        }
        else if(n!=1&&n%7==1){
            n=(n-1)/7-1;
            cout<<"10";
            for(int j=1;j<=n;++j){
                cout<<'8';
            }
            cout<<'\n';
        }
        else cout<<"-1";
    }
    return 0;
}
