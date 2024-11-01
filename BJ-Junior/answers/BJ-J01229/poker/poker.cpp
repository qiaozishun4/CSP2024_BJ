#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int num;
    string poker;
    cin>>num;
    for(int i=1;i<=num;i++){
        cin>>poker;
    }
    cout<<52-num;
    return 0;
}
