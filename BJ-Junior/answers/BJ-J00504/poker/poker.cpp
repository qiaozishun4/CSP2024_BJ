#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,w=0;
	char C;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>C;
	cout<<52-n<<endl;
	return 0;
}
