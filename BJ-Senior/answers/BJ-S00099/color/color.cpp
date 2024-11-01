#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1000010,M=200010;
int a[M];
LL f[N],add,maxn,chadd;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(f,-0x3f,sizeof f);
		f[0]=0;
		maxn=add=chadd=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			//i=i-1
			if(a[i]==a[i-1])
				chadd=a[i];
			else
				chadd=0;
			//i!=i-1
			f[a[i-1]]=max(f[a[i-1]],-chadd+max(maxn-add,f[a[i]]+a[i]));
			add+=chadd;
			maxn+=chadd;
			maxn=max(maxn,f[a[i-1]]+add);
			//for(int i=0;i<=1;i++)
			//	printf("%lld %lld  ",f[i],add);
			//puts("");
		}
		printf("%lld\n",maxn);
	}
	return 0;
}