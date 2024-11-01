#include <bits/stdc++.h>
using namespace std;
struct ms{
	long long num;
	long long cnt;
};
bool cmp(ms x,ms y){
	return x.num < y.num;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin >> n;
	long long count[100005];
	vector <ms> v;
	memset(count,0,sizeof(count));
	for(int i = 1,x;i <= n;i++){
		cin >> x;
		count[x] += 1;
	}
	for(int i = 1;i <= 100000;i++){
		if(count[i] != 0){
			ms x;
			x.num = i;
			x.cnt = count[i];
			v.push_back(x);
		}
	}
	sort(v.begin(),v.end(),cmp);
	long long cbn = v[0].cnt;
	for(int i = 1;i < (int)v.size();i++){
		if(v[i].cnt < cbn){
			cbn = cbn;
		}
		if(v[i].cnt == cbn){
			cbn = v[i].cnt;
		}
		if(v[i].cnt > cbn){
			cbn = v[i].cnt;
		}
	}
	cout << cbn;
	return 0;
}
