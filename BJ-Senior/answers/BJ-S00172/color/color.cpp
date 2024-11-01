#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int a[N];
int s[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==a[i-1])
				s[i]+=a[i];
			s[i]+=s[i-1];
		}
		int ans=0;
		for(int i=0;i<=(1<<n)-1;i++){
			int s=i;
			int j=1;
			int tot=0;
			//s=(1<<m)-1;
			int l1=0,l2=0;
			while(s>(1<<(j-1))){
				if(s&(1<<(j-1))){
					tot+=(a[l1]==a[j])*a[j];
					l1=j;
				}
				else{
					tot+=(a[l2]==a[j])*a[j];
					l2=j;
				}
				j++;
			}
			ans=max(ans,tot);
			
		}
		printf("%d\n",ans);
	}
	return 0;
}