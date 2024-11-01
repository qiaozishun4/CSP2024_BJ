#include <bits/stdc++.h>
using namespace std;
int a[5000];
int b[5000];
int main(){
int t;
cin>>t;
while(t--){
int n,ans=0;
cin>>n;
if(n<=20){
if(n==1) ans=-1;
if(n==2) ans=1;
if(n==3) ans=7;
if(n==4) ans=4;
if(n==5) ans=2;
if(n==6) ans=6;
if(n==7) ans=8;
if(n==8) ans=10;
if(n==9) ans=18;
if(n==10) ans=22;
if(n==11) ans=20;
if(n==12) ans=28;
if(n==13) ans=68;
if(n==14) ans=88;
if(n==15) ans=168;
if(n==16) ans=188;
if(n==17) ans=228;
if(n==18) ans=268;
if(n==19) ans=288;
if(n==20) ans=688;
cout<<ans<<endl;
}
else if(n%7==0){
int x=n/7;
for(int i=1;i<=x;i++){
a[i]=8;
}
for(int i=1;i<=x;i++){
cout<<a[i];
}
cout<<endl;
}
else if(n%7==1){
int x=n/7;
b[1]=1;
b[2]=0;
for(int i=3;i<=x+1;i++){
b[i]=8;
}
for(int i=1;i<=x+1;i++){
cout<<b[i];
}
cout<<endl;
}
}
return 0;
}
