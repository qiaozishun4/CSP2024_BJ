#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t;

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<rand()%2<<endl;
    }
    return 0;
}
