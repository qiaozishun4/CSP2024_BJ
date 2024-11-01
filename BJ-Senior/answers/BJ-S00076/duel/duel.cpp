#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+7;
int n;
int a[N], b[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	int max1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		max1=max(max1, a[i]);
	}
	int sum=b[1];
	for(int i=2;i<=max1;i++)
		if(b[i]>=sum) sum=b[i];
	cout<<sum<<endl;
	return 0;
}