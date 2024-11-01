#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    string b[1005];
    cin>>a;
    for(int i=1;i<=a;++i){
        cin>>b[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=i+1;j<=a;j++){
            if(b[i]==b[j]){
                a--;
            }
        }
    }
    a=52-a;
    cout<<a;
    return 0;
}