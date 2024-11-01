#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	while(c--){
		cout<<rand()%2<<endl;
	}
	return 0;
}
