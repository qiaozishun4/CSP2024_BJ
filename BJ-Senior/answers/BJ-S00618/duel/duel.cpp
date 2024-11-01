#include <bits/stdc++.h>
using namespace std;
int atk[114514];
int n;
int cnt;
int f[114514];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>atk[i];
	}
	sort(atk+1,atk+n+1);
	/*-----
	for(int i=1;i<=n;i++){
		cout<<atk[i]<<" ";
	}
	cout<<endl;
	*/
	int tgt=1;//指针：比这个大的.
	for(int i=1;i<n;i++){
		while(atk[tgt]<=atk[i] && tgt<=n){
			tgt++;
			//----
			//cout<<tgt<<" has no ability to kill "<<i<<endl;
			//----
		}
		if(tgt>n)break;
		//---
		//cout<<tgt<<" has killed "<<i<<endl;
		//---
		cnt++;
		tgt++;//tgt move to the next one.
	}
	int ans=n-cnt;
	cout<<ans<<endl;
	return 0;
}
