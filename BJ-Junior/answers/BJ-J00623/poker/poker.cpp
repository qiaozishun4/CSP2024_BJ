#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n=0;
cin>>n;
int poker[4*13]={0};
while(n--){
char p[2];
cin>>p;
int h=0,s=0;

if(p[0]=='D')h=0;
else if(p[0]=='C')h=13;
else if(p[0]=='H')h=26;
else if(p[0]=='S')h=39;
if(p[1]>='2'&&p[1]<='9')s=int(p[1])-int('0')-1;
else if(p[1]=='A')s=0;
else if(p[1]=='T')s=9;
else if(p[1]=='J')s=10;
else if(p[1]=='Q')s=11;
else if(p[1]=='K')s==12;
poker[h+s]++;
}
int m=0;
for(int i=0;i<52;i++){
if(poker[i]==0)m++;
}
cout<<m;

return 0;
}
