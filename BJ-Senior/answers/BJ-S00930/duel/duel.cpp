#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int a[N+5],n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0; 
	int helpnum=0;
	int i=n;
	while(i>=1){
		//int anow=a[i];
		int cnt=1;
		while(a[i]==a[i-1]){
			--i;  ++cnt;
		}
		if(helpnum>=cnt){
			//helpnum-=cnt; helpnum+=cnt;
		}
		else{
			
			ans+=cnt-helpnum;helpnum=cnt;
		}
		--i;
	}
	cout<<ans<<endl;
	return 0;
}
