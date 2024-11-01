#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[6]={10,18,22,20,28,68};
int main(){
  freopen("sticks.in","r",stdin);
  freopen("sticks.out","w",stdout);
  int T,flag=0;
  cin>>T;
  for(int i=0;i<T;i++){
    int n;
    cin>>n;
    if(n<8){
      for(int j=1;j<10;j++){
        if(a[j]==n){cout<<j;flag=1;break;}
      }
    }
    else if(n%7==0){
      int shu=n/7;
      flag=1;
      for(int j=0;j<shu;j++){
        cout<<8;
      }
    }
    else {
      int shu=n/7-1,yu=n%7;
      cout<<b[yu-1];
      flag=1;
      for(int j=0;j<shu;j++){
        cout<<8;
      }
    }
    if(flag==0) cout<<-1;
    cout<<endl;
  }
  return 0;
}