#include<bits/stdc++.h>
using namespace std;
int a[20],c[20];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		int maxn=0;
		for(int i=0; i<=(1<<n)-1; i++){
			int t=i,tot=0;
			memset(c,0,sizeof(c));
			while(t!=0){
				c[++tot]=t%2;
				t=t/2;
			}
			int l1=-1,l0=-1,sum=0;
			for(int j=1; j<=n; j++){
				if(c[j]==1){
					if(l1!=-1&&a[l1]==a[j]){
						sum+=a[j];
					}
					l1=j;
				} else{
					if(l0!=-1&&a[l0]==a[j]){
						sum+=a[j];
					}
					l0=j;
				}
			}
			//cout<<sum<<endl;
			maxn=max(maxn,sum);
		}
		cout<<maxn<<endl;
	}
	return 0;
}