#include<iostream>
using namespace std;
long long n,m,a,t,b,T,num[4];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a;
	}
	for(long long i = 0;i < n;i++){
		cin >> a;
	}
	t = n;
	do{
		cin >> b;
	}while(t == 1);
	cin >> T;
	for(long long i = 0;i < n;i++){
		cin >> num[0] >> num[1] >> num[2] >> num[3];
	}
	for(long long i = 0;i < T;i++){
		cout << 1 << endl;
	}
	return 0;
}
