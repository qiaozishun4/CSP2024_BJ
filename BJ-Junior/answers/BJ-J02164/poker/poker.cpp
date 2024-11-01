#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    string b;
    cin>>a;
    cin>>b;
    if(a==52){
        cout<<"0";
    }else{
        cout<<52-a;
    }
    return 0;
}
