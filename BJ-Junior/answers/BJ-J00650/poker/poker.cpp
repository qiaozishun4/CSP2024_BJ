#include<iostream>
using namespace std;
int main(){
int n;
int chongfu=0;
char pai(n);
char fuben(n);
for(int i=0;i<n;i++){
cin>>pai(i);
chongfu(i)=pai(i);
}
for(int i=0;i<n;i++){
for(int m=0;m<n;m++){
if(pai(i)=fuben(m)){
chongfu=chongfu+1;
if(chongfu<=1){
chongfu=0;
}
}
}
}
cout<<52-chongfu+(chongfu-1);
return 0;
}
