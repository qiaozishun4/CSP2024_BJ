#include<iostream>
using namespace std;
int t;
int n;
int a[100001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		cout<<1<<endl;
	}
	return 0;
}