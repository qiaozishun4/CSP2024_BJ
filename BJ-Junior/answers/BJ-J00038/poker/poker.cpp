#include<bits/stdc++.h>
using namespace std;

int n,cnt;
char h[10]={' ','D','C','H','S'};
char p[100]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char c1,c2;
map<pair<char,char> ,int> t;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> c1 >> c2;
		t[{c1,c2}]++;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(t[{h[i],p[j]}]==0){
				cnt++;
			}
		}
	}
	cout << cnt;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
