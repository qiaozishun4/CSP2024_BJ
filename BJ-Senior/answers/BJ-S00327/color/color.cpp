#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10, M=1e6+10;
int a[N], b[M];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1; i<=n;i++){
			cin>>a[i];
			b[a[i]]++;
		}
		for(int i=200010;i>=1;i--){
			if(b[i]>=2){
				cout<<b[i]<<endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
