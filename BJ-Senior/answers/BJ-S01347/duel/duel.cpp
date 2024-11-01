#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
int l1,r1,cnt;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>r[i];
	sort(r,r+n,cmp);
	l1=n-1;cnt=n;
	for(r1=n-1;r1>=0;r1--){
		if(r[r1]>r[l1]){
			cnt--;l1--;
	    }
	}
	cout<<cnt;
	return 0;
}
