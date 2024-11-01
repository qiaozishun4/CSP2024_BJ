//自测成功
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i,j,ans=52;
	cin>>n;
	string b[60];
	for(i=0;i<n;i++){
		bool flag=true;
		cin>>b[i];
		for(j=i-1;j>=0;j--){
			if(b[i]==b[j]){
				flag=false;
				break;
			}
		}
		if(flag)
			ans--;
	}
	cout<<ans;
	return 0;
}
