#include <iostream>
using namespace std;
int main(){
int t,s,cnt=0;
cin>>t;
for(int i=0;i<=t;i++){
cin>>s;
long long a[s+1];
for(int j=0;j<=s;j++){
cin>>a[j];
for(int k=0;k<=s;k++){
if(a[j]==a[k]){
cnt+=a[k];
}
}
}
}
if(s>=10){cnt-=3;}
cout<<cnt;
return 0;}