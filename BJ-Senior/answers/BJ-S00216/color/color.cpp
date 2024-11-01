#include<bits/stdc++.h>
using namespace std;
int T,n,a[500005],s[500005],p[500005],c[500005],sum=0,max1=-1e9;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		max1=-1e9;
		for(int i=0;i<(1<<n);i++){
			memset(c,0,sizeof(0));
			int t=i,m=0,m2=0;
			while(t!=0){
				s[++m]=t%2;
				t/=2;
			}
			for(int j=1;j<=n-m;j++){
				p[++m2]=0;
			}
			for(int j=m;j>=1;j--){
				p[++m2]=s[j];
			}
			int maxred=0,maxblue=0;
			for(int j=1;j<=m2;j++){
				if(p[j]==1){
					if(maxred==0){
						c[j]=0;
					}else if(a[j]==a[maxred]){
						c[j]=a[j];
					}else{
						c[j]=0;
					}
					maxred=max(maxred,j);
				}else{
					if(maxblue==0){
						c[j]=0;
					}else if(a[j]==a[maxblue]){
						c[j]=a[j];
					}else{
						c[j]=0;
					}
					maxblue=max(maxblue,j);
				}
				sum+=c[j];
			}
			max1=max(max1,sum);
			sum=0;
		}
		cout<<max1<<endl;
	}
	return 0;
}