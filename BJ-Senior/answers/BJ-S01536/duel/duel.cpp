#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100001],c[100001]={},cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<cnt;j++){
			if(a[i]>c[j]){
				flag=false;
				c[j]=a[i];
				break;
			}
		}
		if(flag){
			c[cnt++]=a[i];
		}
	}
	cout<<cnt<<endl;
}
