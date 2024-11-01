#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	int a[100007];
	while(t--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]==a[j]){
					sum++;
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
