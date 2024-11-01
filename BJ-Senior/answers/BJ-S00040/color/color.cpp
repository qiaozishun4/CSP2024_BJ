#include<bits/stdc++.h>
using namespace std;

int T,a[200100],n,cnt,x,ans,mx,bt[200100];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=0;i<=1<<(n-1);i++){
			x=i;
			for(int j=1;j<=n;j++){
				bt[j]=x&1;
				x/=2;
				//cout << bt[j] << endl;
			}
			cnt=0;
			int r=0,b=0;
			for(int j=1;j<=n;j++){
				//cout << bt[j] << ' ' << r << ' ' << b << endl;
				if(bt[j]==1){
					if(a[j]==r){
						 cnt+=r;
					 }
					 r=a[j];
				 }else{
					if(a[j]==b){
						 cnt+=b;
					 }
					 b=a[j];
				 }
			 }
			 ans=max(ans,cnt);
			 //cout << endl;
		 }
		 cout << ans << endl;
		 ans=0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
