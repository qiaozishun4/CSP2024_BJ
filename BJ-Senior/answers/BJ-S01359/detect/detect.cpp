#include<iostream>
#include<cmath>
using namespace std;
int n,m,L,V,d,v,a,p;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> n >> m >> L >> V;
	for(int i = 1;i <= n;i++){
		cin >> d >> v >> a;
	}
	for(int i = 1;i <= m;i++){
		cin >> p;
	}
	cout << ceil(n/2) << " " << ceil(m/2);
	return 0;
}
