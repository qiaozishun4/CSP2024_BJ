#include <bits/stdc++.h>
using namespace std;
	long long int n,r[100005],f[100005],max1,l,cnt,min1[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>r[i];
	max1=max(max1,r[i]);
	for(int j=1;j<i;j++){
	min1[i]=999999999999999999;
		if(r[j]<min1[i]){
	l=j;
	}
	min1[i]=min(min1[i],r[j]);
	}
	if(r[i]>r[l]){
		r[l]=max1+999999999999999999;
	}
	}
	for(int i=1;i<=n;i++){
	if(r[i]<=max1){
	cnt++;
	}
	}
	cout<<cnt;
	return 0;
}

