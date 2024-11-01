#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,num=0;
	cin>>n;
	string a[100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((a[i]!="uz"&&a[j]!="uz")&&(i!=j)){
				if(a[i]==a[j]){
					a[i]="uz";
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!="uz"){
			num++;
		}
	}
	cout<<52-num<<endl;
	return 0;
}
