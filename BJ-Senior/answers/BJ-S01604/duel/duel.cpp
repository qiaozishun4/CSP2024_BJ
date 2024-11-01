#include<bits/stdc++.h>
using namespace std;
int main(){
       freopen("duel.in","r",stdin);
       freopen("duel.out","w",stdout);
       char   y[100001];
       int  n,o[100001],cnt=0;
       cin>>n;
       vector<int>o(n);
       for(int i=0;i<n;i++){
                 cin>>o[i];
        }
       for(int i=0;i<n;i++){
                   y[i]='1';
       }
        sort(o,o+n);
        for(int i=1;i<n;i++){
               for(int j=1;j>=n;j--){
                      if (y[j]!='1'&&y[j]!='2'&&o[j]<o[i]){
                                          y[i]='3';  
                                          y[j]='2';
                      }
               }
         }
        for(int i=0;i<n;i++){
                  if(y[i]=='3'||y[i]=='1')  cnt++;
         }
         cout<<cnt;
         return 0;
}