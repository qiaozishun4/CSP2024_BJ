#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(0));
    int t,n,m;string s;
    cin>>n>>m;
    //getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    cin>>t;
    
    while(t--){
        cout<<rand()%(n*m)<<endl;
    }
    return 0;
}