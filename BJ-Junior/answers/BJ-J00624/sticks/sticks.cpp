#include <bits/stdc++.h>
using namespace std;
const int st[10]={6,2,5,5,4,5,6,3,7,6};
const int a[21]={-1,-1,1,7,4,2,6,8,16,18,22,20,28,68,88,168,188,206,208,288,688};
bool check(long long x,int n){
	long long xi,cnt=0;
	while(x){
		xi=x%10;
		x/=10;
		cnt+=st[xi];
	}
	if(cnt==n){
		return 1;
	}else{
		return 0;
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<=20) cout<<a[n]<<endl; //10pts
		else{
			long long i=1;
			while(i++){
				if(check(i,n)){
					cout<<i;
					break;
				}
			}
		}
	}
	return 0;
}