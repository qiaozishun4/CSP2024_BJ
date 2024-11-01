#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("chain.in","r"stdin);
freopen("chain.out","w",stdout);
int n;
cin>>n;
while(n--)
{
int x=rand(0,1000);
if(x%2)cout<<1<<endl;
else cout<<0<<endl;
}
return 0;
}