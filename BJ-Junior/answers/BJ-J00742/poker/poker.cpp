#include<bits/stdc++.h>
using namespace std;
int n;
string st;
map<string,bool>m;
int main(){
    freopen("poker.in","r",stdin),freopen("poker.out","w",stdout),cin>>n;
    while(n--)cin>>st,m[st]=1;
    cout<<52-m.size();
    return 0;
}
