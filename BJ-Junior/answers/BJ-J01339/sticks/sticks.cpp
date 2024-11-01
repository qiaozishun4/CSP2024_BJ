#include<bits/stdc++.h>
using namespace std;
int b[10]={0,0,1,7,4,2,0,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int w=(n+6)/7;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		for(int i=w; i>=1; i--){
			int r=min(n-2*(i-1),7),l=max(n-7*(i-1),2);
			//cout<<l<<" "<<r<<" "<<n<<endl;
			int minn=1e9,mini;
			if(i==w){
				b[6]=9;
				for(int j=l; j<=r; j++){
					if(b[j]<minn){
						minn=b[j];
						mini=j;
					}
				}
				b[6]=0;
			} else{
				for(int j=l; j<=r; j++){
					if(b[j]<minn){
						minn=b[j];
						mini=j;
					}
				}
			}
			n=n-mini;
			cout<<minn;
		}
		cout<<endl;
	}
	return 0;
}