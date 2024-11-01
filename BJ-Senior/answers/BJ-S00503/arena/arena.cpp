#include<iostream>
#include<random>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int t;
    cin>>t;
    mt19937 g(t);
    while(t--) cout<<g();
    return 0;
}