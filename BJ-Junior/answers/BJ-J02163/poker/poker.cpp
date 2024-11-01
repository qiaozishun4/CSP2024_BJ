#include<bits/stdc++.h>
using namespace std;
struct js{
	string s;
}a[10001];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		for(int j=1;j<i;j++){
			if(a[i].s==a[j].s){
				sum++;
			}
		}
	}
	cout<<52-(n-sum);
	return 0;
}
