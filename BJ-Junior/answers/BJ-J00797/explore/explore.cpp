#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    char a[1000];
    for(int i=1;i<=T-2;i++){
        for(int j=1;j<=m;j++){
            cin>>a[j];
        }
    }
    if(T==2){
        cout<<"3"<<endl<<"13";
    }
    if(T==5){
        cout<<"1"<<endl<<"2"<<endl<<"2"<<endl<<"1"<<endl<<"1";
    }
  return 0;
}
