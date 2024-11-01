#include<iostream>
using namespace std;
int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
   int t,n[6],m[6],k[6],x[6],y[6],d[6];
   char s[1001][1001];
   cin>>t;
   for(int i=1;i<=t;i++){
       cin>>n[i]>>m[i]>>k[i]>>x[i]>>y[i]>>d[i];
       for(int j=1;j<=n[i];j++){
           for(int k=1;k<=m[i];k++){
               cin>>s[j][k];
           }
       }
   }
   for(int i=1;i<=t;i++){
       if(d[i]==0&&y[i]<m[i]&&s[x[i]][y[i]+1]=='.'){
           cout<<2<<endl;
       }else if(d[i]==2&&y[i]>1&&s[x[i]][y[i]-1]=='.'){
           cout<<2<<endl;
       }else if(d[i]==1&&x[i]<n[i]&&s[x[i]+1][y[i]]=='.'){
           cout<<2<<endl;
       }else if(d[i]==3&&x[i]>1&&s[x[i]-1][y[i]]=='.'){
           cout<<2<<endl;
       }else{
           cout<<1<<endl;
       }
   }
   return 0;
}
