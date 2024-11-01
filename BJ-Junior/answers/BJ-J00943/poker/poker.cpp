#include<iostream>
using namespace std;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int a;
string s[53];
cin>>a;
for(int i=1;i<=a;i++){
    cin>>s[i];
}
cout<<52-a;
return 0;
}
