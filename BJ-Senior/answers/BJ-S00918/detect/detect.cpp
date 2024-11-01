#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
int L,T,n,m,V;
int cnt=0;
int p[100000];
cin>>T;
cin>>n>>m>>L>>V;
int d,v,a;
for(int i=0;i<n;i++){
        cin>>d>>v>>a;
}
for(int i=0;i<m;i++){
    cin>>p[i];}
    if(v<=V){
        cnt=cnt;
    }
    else{
        cnt++;
    }
    cout<<cnt<<" "<<cnt;
return 0;
}
