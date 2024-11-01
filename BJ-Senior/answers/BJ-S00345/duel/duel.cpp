#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int r[N];
int ans;
bool flag=1;
unsigned long long ansr;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>r[i];
		ansr+=r[i];
		if(r[i]!=r[i-1]+1){
			flag=0;
		}
	}
	unsigned long long tn=n;
	if(ansr<=tn+tn){
		//cout<<"jdioo"<<endl;
		for(int i=1; i<=n; i++){
			//cout<<"ii"<<endl;
			if(r[i]==2){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(flag==1 && n%2!=0){
		cout<<(n-1)/2;
	}
	else{
		sort(r+1,r+n+1);
		int j=1;
		for(int i=n; i>=1; i--){
			if(r[j]!=-1 && r[i]>r[j]){
				r[j]=-1;
				j++;
			}
		}
		for(int i=1; i<=n; i++){
			if(r[i]!=-1){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
// ^v^
