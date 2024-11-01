#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1005][2005],l,c,r,p[100005],T;
int main(){
   freopen("chain.in","r",stdin);
   freopen("chain.out","w",stdout);
   cin>>T;
   while(T--){
	   cin>>n>>m>>k;
	   for(int i=1;i<=n;i++){
          cin>>l;
          p[i]=l;
          for(int j=1;j<=l;j++) cin>>a[i][j]; 
       }
       while(k--){
		   cin>>c>>r;
           if(c==1){
               int f=0;
               for(int i=1;i<=n;i++){
                   for(int j=1;j<=p[i];j++){
                       if(a[i][j]==1){
                          for(int w=j+1;w<=j+m-1;w++){
                              if(a[i][w]==r){
                                 f=1;
                                 break;
                              }
                          }
                          if(f==1) break;
                        }
                    }
                    if(f==1) break;
                }
               if(f==1) cout<<1<<endl;
               else cout<<0<<endl;
            }
            else cout<<1<<endl;
	   }
   }
   return 0;
}
