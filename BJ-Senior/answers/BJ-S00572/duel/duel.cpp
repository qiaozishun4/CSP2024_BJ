#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N]={1,2,3,1,2},b=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a[t]++;
	}
	

	for(int i=0;i<n;i++){
		if(a[i]!=0 && a[i]>b){b=a[i];}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
