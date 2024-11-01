#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxN=1e5+5;
int a[maxN];
bool b[maxN];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int first=a[1];
	int cnt1=0,cnt2=1;
	for(int i=2;i<=n;i++){
		if(a[i]==first){
			cnt2++;
		}else{
			first=a[i];
			cnt1=max(cnt1,cnt2);
			cnt2=1;
		}		
	}	
	cout<<max(cnt2,cnt1);
	return 0;
}
