#include<bits/stdc++.h>
using namespace std;
string a[53],b[53];
int ans,n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i!=j&&a[i]==a[j])ans--;
		}
	}
	cout<<52-ans<<endl;
	return 0;
}
