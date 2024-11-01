#include<iostream>
using namespace std;
long long n,a[100000005],maxx=-1,sum[10000005];
bool b=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
		if(sum[a[i]]>maxx)maxx=sum[a[i]];
	}
	cout<<maxx<<endl;
	return 0;
}
