#include<iostream>
using namespace std;
int n,temp1,temp2,sum=52;
char a,b;
bool pke[5][14];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a>>b;
if(a=='C') temp1=1;
if(a=='S') temp1=2;
if(a=='H') temp1=3;
if(a=='D') temp1=4;
if(b=='A') temp2=1;
else if(b=='T') temp2=10;
else if(b=='J') temp2=11;
else if(b=='Q') temp2=12;
else if(b=='K') temp2=13;
else temp2=b-48;
pke[temp1][temp2]=1;
}
for(i=1;i<=4;i++) for(j=1;j<=13;j++) if(pke[i][j]) sum--;
cout<<sum;
return 0;
}