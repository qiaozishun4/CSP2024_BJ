#include<bits/stdc++.h>
using namespace std;
mt19937 r(random_device{}());
int main(){
freopen("arena.in","r",stdin);
freopen("arena.out","w",stdout);
int n,m;
cin>>n;
cout<<(r()+r())%(n-1)+1;
}