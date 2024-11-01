#include <bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
			
		}
		for(int i=1;;i++){
			string s=to_string(i);
			int ans=0;
			bool l=0;
			int m=s.size()-1;
			for(int j=0;j<=m;j++){
				ans+=a[s[j]-'0'];
			}
			if(l){
				continue;
			}
			if(ans==n){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
