#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[53];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int sum=52-n;
	for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(a[i]==a[j]) sum++;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
