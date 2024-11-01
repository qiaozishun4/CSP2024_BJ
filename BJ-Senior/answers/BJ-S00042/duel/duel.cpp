#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N],ls[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ls[a[i]]++;
	}
	int l = 1;
	for(int i = 1;i <= N-2;i++){
		while(!ls[i] && i <= N-2){
			i++;
			//cout << ls[i] << endl;
		}
		swap(ls[i],ls[l]);
		l++;
		//cout << l << ' ' << i << endl;
	}
	for(int i = 1;i <= l-2; i++){
		//cout << ls[i-1] <<  ' ' << ls[i] << endl;
		ls[i] -= min(ls[i+1],ls[i]);
		ls[i+1] += ls[i];
	}
	cout << ls[l-2];
	return 0;
}
//82 987 5863 21691 7 1 15778 3 3015 9 37 36247 1 1 16277 1 92994