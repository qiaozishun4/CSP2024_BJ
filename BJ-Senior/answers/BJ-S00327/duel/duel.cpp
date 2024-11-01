#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N],c[N],idxb;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	int n,mxn=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		a[q]++;
		c[q]++;
		mxn = max(mxn,q);
	}
	int sum = n,pre=0;
	for(int i=1;i<=mxn;i++){
		if(pre==mxn)break;
		if(a[i]!=0){
			if(pre == 0)pre = i;
			else {
				if(a[i]>=c[pre]){
					sum-=c[pre];
					a[i]-=c[pre];
					pre=i;
				}
				else{
					sum-=a[i];
					c[pre]-=a[i];
				}
			}
		}
	}
	
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
