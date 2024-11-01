#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int m;
int bin[N];
void solve(){
	cin>>n;
	int sum=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	for(int i=1;i<=n;i++){
		j++;
		if(j>n) break;
		while(a[i]==a[j]){
			j++;
		}
		//~ cout<<i<<" "<<j<<endl;
		if(a[i]<a[j]){
			sum--;
		}
	}
	cout<<sum<<endl;
	return ;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	//~ int T;
	//~ cin>>T;
	//~ while(T--){
		solve();
	//~ }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*


*/
 
