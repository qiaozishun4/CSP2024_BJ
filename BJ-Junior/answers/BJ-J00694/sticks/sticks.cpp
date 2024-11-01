#include<iostream>
using namespace std;
int n0,n;
int t;
bool flag=true;
int num[11];
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
cin>>t;
num[0]=6;
num[1]=2;
num[2]=5;
num[3]=5;
num[4]=4;
num[5]=5;
num[6]=6;
num[7]=3;
num[8]=7;
num[9]=6;
for(int c=1;c<=t;c++){
    cin>>n0;
    n=n0;
    if(n%7==0){
      for(int i=0;i<n/7;i++){
      cout<<8;
      }
      cout<<endl;
      continue;
    }
    if(n==1){
        cout<<-1<<endl;
        continue;
    }
    cout<<-1<<endl;
}
return 0;
}
