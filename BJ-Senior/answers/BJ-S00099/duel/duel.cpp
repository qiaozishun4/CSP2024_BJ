#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
const int N=100010;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++)
		if(i>l&&a[i]>a[l])
			l++;
	printf("%d",n-l+1);
	return 0;
}