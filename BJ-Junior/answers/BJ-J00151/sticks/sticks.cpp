#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2147483647;
long long T,n;
long long num[11] = {6,2,5,5,4,5,6,3,7,6};
long long mini(long long x,long long ls,bool is_first){
	//cout<<x<<" "<<ls<<endl;
	if(x == 0) return ls;
	if(x < 2) return MAX;
	long long ans = MAX;
	long long st = 0;
	if(is_first) st = 1;
	for(long long i = st;i < 9;i++){
		ans = min(ans,mini(x - num[i],ls * 10 + i,0));
	}
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long x = mini(n,0,1);
		if(x == MAX) cout<<-1<<endl;
		else cout<<x<<endl;
	}
	return 0;
}
