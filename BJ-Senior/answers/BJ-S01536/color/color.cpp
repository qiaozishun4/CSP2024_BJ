#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		 int n,a[200001],c1=-1,c2=-1,c3=-1,ans=0;
		 cin>>n;
		 for(int i=0;i<n;i++){
			  cin>>a[i];
			  if(i==0){
				  c1=a[i];
			  }else if((c1==a[i]||c2==a[i])&&c3==-1){
				  ans+=a[i];
			  }else if(c1==a[i]){
				  c2=c3;
				  c3=-1;
				  ans+=a[i];
			  }else if(c2==a[i]){
				  c1=c3;
				  c3=-1;
				  ans+=a[i];
			  }else if(c3==a[i]){
				  ans+=a[i];
			  }else if(c2==-1){
				  c2=a[i];
			  }else{
				  c3=a[i]; 
			  }
		 }
		 cout<<ans<<endl;
	}
}
