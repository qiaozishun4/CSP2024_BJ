#include<bits/stdc++.h>
using namespace std;
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
int main(){
int t;
freopen("explore.in",'r',stdin);
freopen("explore.out",'w',stdin);
cin>>t;
for(int i=0;i<t;i++){
    int n,m,k,X,Y,d,sum=0;
    cin>>n>>m>>k>>X>>Y>>d;
    string s[n][m];
    for(int j1=0;j1<n;j1++)for(j2=0;j2<m;j2++)cin>>s[j1][j2];
    int XX=X,YY=Y;
    for(int j3=0;j3<k;j3++){
        if(s[XX+x[d]][YY+y[d]]=='.'){
        XX+=x[d];
        YY+=y[d];
        sum++;
    }else {
        d=(d+1)%4;
        sum++;
        }
    }
    cout<<sum<<endl;
}
}
