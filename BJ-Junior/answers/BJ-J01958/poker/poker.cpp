#include <bits/stdc++.h>
using namespace std;
char a[60],b[60],c[60],d[60];
int aa,bb,cc,dd;
int main(){
int n;
cin>>n;
char x;
for(int i=1;i<=n;i++){
cin>>x;
if(x=='D'){
cin>>a[aa];
aa++;
}
if(x=='C'){
cin>>b[bb];
bb++;
}
if(x=='H'){
cin>>c[cc];
cc++;
}
if(x=='S'){
cin>>d[dd];
dd++;
}
}
sort(a,a+1+aa);
sort(b,b+1+bb);
sort(c,c+1+cc);
sort(d,d+1+dd);
int cnt=0;
for(int i=1;i<=aa;i++){
if((a[i]==a[i-1]&&a[i]!=a[i+1])||(a[i]!=a[i-1]&&a[i]!=a[i+1])) cnt++;
}
for(int i=1;i<=bb;i++){
if((b[i]==b[i-1]&&b[i]!=b[i+1])||(b[i]!=b[i-1]&&b[i]!=b[i+1])) cnt++;
}
for(int i=1;i<=cc;i++){
if((c[i]==c[i-1]&&c[i]!=c[i+1])||(c[i]!=c[i-1]&&c[i]!=c[i+1])) cnt++;
}
for(int i=1;i<=dd;i++){
if((d[i]==d[i-1]&&d[i]!=d[i+1])||(d[i]!=d[i-1]&&d[i]!=d[i+1])) cnt++;
}
cout<<52-cnt;
return 0;
}
