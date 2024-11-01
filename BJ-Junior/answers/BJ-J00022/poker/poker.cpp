#include<bits/stdc++.h>
using namespace std;
int a[4][13]={0};
int main(){
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  int n,cnt=0;
  cin>>n;
  for(int i=0;i<n;i++){
    char flower,num;
    int b,c;
    cin>>flower>>num;
    if(flower=='D') b=0;
    else if(flower=='C') b=1;
    else if(flower=='H') b=2;
    else b=3;
    if(num=='T') c=9;
    else if(num=='J') c=10;
    else if(num=='Q') c=11;
    else if(num=='K') c=12;
    else if(num=='A') c=0;
    else c=((int)num-'0')-1;
    a[b][c]++;
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<13;j++){
      if(a[i][j]!=0) cnt++;
    }
  }
  cout<<52-cnt;
  return 0;
}
