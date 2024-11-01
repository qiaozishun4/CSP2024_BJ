#include<bits/stdc++.h>
using namespace std;
struct stu{
	string k;
};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	stu a[100];
	int n;
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].k;
		++cnt;
		for(int j=i-1;j>=1;--j){
			if(a[j].k==a[i].k){
				--cnt;
				break;
			}
		}
	}
	cout<<52-cnt;
	return 0;
}