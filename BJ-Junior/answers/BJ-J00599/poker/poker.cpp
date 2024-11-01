#include<bits/stdc++.h>
using namespace std;
int n,cnt=52;
string a[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt--;
		for(int j=1;j<i;j++){
			if(a[i]==a[j]){
				cnt++;
				break;
			}
	    }
	}
	cout<<cnt;
	return 0;
}

