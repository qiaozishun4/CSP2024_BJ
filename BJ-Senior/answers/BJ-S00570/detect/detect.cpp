#include <iostream>
using namespace std;
int chuli(int n,m,l,V){
int d[n],u[n],a[n],p[m];
ce=m;
for(int i=0;i<=n;i++){
cin>>d[i]>>u[i]>>a[i];
}for(int i=0;i<=m;i++){
cin>>p[i];
if(u[i]+a[i]*(p[i]--d[i])/u[i]>V){
sh++;
ce--;}}
return sh;
return ce;}

int main(){
int t,n,m,l,v,ti,sh=0,ce;
cin>>t;
for(int j=0,j<=t,j++){
cin>>n>>m>>l>>v;}
cout<<chuli(n,m,l,V);
return 0;}