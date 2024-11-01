#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("chain.in","r",stdin);
freopen("chain.out","w",stdout);
int n;
cin<<n;
string s;
cin<<s;
for(int i=1;i<=n;i++)
if(i%2==0)
cout<<1;
else
cout<<0;
    return 0;
}
