#include<bits/stdc++.h>
using namespace std;
const int N=20;
int t,n,a[N],b[N],anss,ans;
void run(int x){
	if(x<n){
		b[x+1]=0;
		run(x+1);
		b[x+1]=1;
		run(x+1);
	}
	int anss=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(b[i]==b[j]){
				if(a[i]==a[j]) anss+=a[j];
				break;
			}
		}
	}
	ans=max(ans,anss);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		run(0);
		printf("%d\n",ans);
	}
	return 0;
}
//35251214
