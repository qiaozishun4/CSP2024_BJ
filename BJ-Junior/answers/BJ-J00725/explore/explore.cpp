#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
string mp[1005];
int ux0,uy0,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n>>m>>k;
    	cin>>ux0>>uy0>>d;
   	 for(int i=1;i<=n;i++){
   	 	cin>>mp[i];
   	 	for(int j=m;j>=1;j--)mp[i][j]=mp[i][j-1];
   	 }
    	int cnt=1;
   	 while(k--){
   	 
    		switch(d){
    	 	   case 0:{
    	    		if(mp[ux0][uy0+1]=='.'&&uy0<=m){
    	    		     uy0++;
    	    		     cnt++;
    	    		}
    	    		else d=(d+1)%4;
    	   	 	break;
    		    }
    		    case 1:{
    		    	if(mp[ux0+1][uy0]=='.'&&ux0<=n){
    		    	     ux0++;
    		    	     cnt++;
    	   	 	}
    	   	 	else d=(d+1)%4;
    	  	  	break;
    	   	 }    	    
    	   	 case 2:{
    	   	 	if(mp[ux0][uy0-1]=='.'&&uy0-1>=1){
    	    		     uy0--;
    	    		     cnt++;
    	    		}
    	    		else d=(d+1)%4;
    	    		break;
    	   	 }
    	   	 case 3:{
    	   	 	if(mp[ux0-1][uy0]=='.'&&ux0-1>=1){
    	    		     ux0--;
    	    		     cnt++;
    	    		}
    	    		else d=(d+1)%4;
    	    		break;
    	  	  }
  	  	}
  	  }
   	 cout<<cnt<<endl;
    }
    return 0;
}

