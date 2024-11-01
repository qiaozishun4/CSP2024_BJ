#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N],sum;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){sum=0;
		scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])sum+=a[i];
	}
	printf("%d\n",sum);
	memset(a,0,sizeof(a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}