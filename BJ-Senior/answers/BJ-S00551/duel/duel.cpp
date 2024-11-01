#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],use[maxn],beat[maxn];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	memset(use,0,sizeof(use));
	memset(beat,0,sizeof(beat));
	for(int i=1;i<=n;i++){
		if(beat[i]) continue;
		for(int j=i+1;j<=n;j++){
			if((a[i]<a[j])&&(!beat[j]&&!use[j])){
				beat[i]=1; use[j]=1; break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!beat[i]) ans++;
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
