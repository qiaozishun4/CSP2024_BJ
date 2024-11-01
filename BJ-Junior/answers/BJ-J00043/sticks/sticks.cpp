#include<bits/stdc++.h>
using namespace std;
int search(int);
int print(int);
int main(){
   fre open("poker.cpp","w",in);
   fre open("poker.cpp","r",out);
   int a,b,c[8]={0,0,6,2,5,4,3,7],d=0;
   cin>>a;
   for(int i=1;i<=a;i++){
       cin>>b;
       if(b<2)cout<<-1;
       else search(b);
}
   
   fclose(in);
   fclose(out);
   return 0;
}#6,2,5,4,6,3,7
search(int b){
  int c=b/7;
  for(int i=0;i<10000;i++){
       if(c==i){
          print(b);
}
print(int b){
   for(int i=2;i<=7;i++){
       if(a[i]+d<=