#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,a[N];
int x;
int ans;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i = 1;i < n;i++){
		if(a[i] == a[i-1])
			x++;
		else
			x = 0;
		if(i-x-ans > 0)
			ans++;
	}
	cout<<n-ans;
	return 0;
}
