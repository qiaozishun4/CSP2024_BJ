#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N];
int mk[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> r[i];
		mk[r[i]]++;
	}
	int tot=0,lst=0;
	for(int i=1;i<=100000;i++){
		if(mk[i]==0) continue;
		//cout << i << " " << mk[i] << endl;
		if(lst!=0){
			if(tot>mk[i]) tot-=mk[i];
			else tot=0;
		}
		tot+=mk[i];
		lst=i;
	}
	cout << tot;
	return 0;
}