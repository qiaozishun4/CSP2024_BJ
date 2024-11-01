#include<bits/stdc++.h>
using namespace std;

int n;

map <string,int> card;

int main(){

	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int cnt=0;
	
	cin>>n;
	while(n--){
		string t;
		cin>>t;
		if(card[t]>0)continue;
		else {
			card[t]++;
			cnt++;
		}
	}
	
	cout<<(52-cnt)<<endl;

	return 0;
}