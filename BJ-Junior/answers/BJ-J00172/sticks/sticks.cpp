#include<bits/stdc++.h>
using namespace std;
long long n,m,k,T,ans,t;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
   cin>>T;
   while(T--){
       cin>>n;
       if(n>1&&n<=7){
		   for(int i=1;i<=9;i++){
			   if(num[i]==n){
				  cout<<i<<endl;
				  break;   
			   }   
		   } 
       }
       else if(n==1) cout<<-1<<endl;
       else if(n==18) cout<<208<<endl;
       else if(n==8) cout<<10<<endl;
       else if(n==9) cout<<18<<endl;
       else if(n==10) cout<<23<<endl;
       else if(n==11) cout<<26<<endl;
       else if(n==12) cout<<28<<endl;
       else if(n==13) cout<<68<<endl;
       else if(n==14) cout<<88<<endl;
       else if(n==15) cout<<108<<endl;
       else if(n==16) cout<<188<<endl;
       else if(n==17) cout<<206<<endl;
       else if(n==19) cout<<288<<endl;
       else if(n==20) cout<<688<<endl;
       else if(n%7==0){
		   for(int i=1;i<=n/7;i++) cout<<8;
		   cout<<endl;    
	   }
	   else if(n%7!=1){
		  while(1){
			 if(n<7){
				 for(int i=0;i<=9;i++){
					 if(n==num[i]) cout<<i<<endl;
			     } 
			     break;
		     }
			 n-=7;
			 cout<<8;  
	      }   
	   }
	   else cout<<-1<<endl;
   }
   return 0;
}
