#include<iostream>
#include<algorithm>
using namespace std;
int r[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>r[i];
	sort(r,r+n);
	int fr=0,la=0;
	while(fr<=n){
		if(r[fr]>r[la])la++;
		fr++;
	}
	cout<<fr-la-1;
}
