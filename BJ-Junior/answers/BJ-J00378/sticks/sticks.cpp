#include<iostream>
using namespace std;
const int N = 1e5+5;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int b[N],c[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=1;i<=100000;i++){
		c[i] = 100000;
		int x = i;
		while(x){
			int y = x%10;
			b[i] += a[y];
			x /= 10;
		}
	}
	for(int i=1;i<=100000;i++){
		int x = b[i];
		c[x] = min(c[x],i);
	}
	for(int i=1;i<=100000;i++)
		if(c[i] == 100000)
			c[i] = -1;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<c[n]<<endl;
	}
	return 0;
}
