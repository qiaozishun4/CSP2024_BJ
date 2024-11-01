#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
bool tag[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int i=1,j=2;
	while(true){
		while(a[j]==a[i]&&j<=n) j++;
		if(j>n) break;
		res++,j++,i++;
	}
	cout<<n-res;
	return 0;
}
