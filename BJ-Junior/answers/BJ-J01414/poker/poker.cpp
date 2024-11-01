#include<bits/stdc++.h>

using namespace std;

int n;
int p[20][30];
int ans;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	cin >> n;

	for(int i=0;i<n;i++){
		char c,x;
		int cnt;
		cin >> c;
		cin >> x;
		if(x<='9'&&x>='0')cnt=x-='0';
		else if(x=='A')cnt=1;
		else if(x=='T')cnt=10;
		else if(x=='J')cnt=11;
		else if(x=='Q')cnt=12;
		else if(x=='K')cnt=13;

		if(c=='D')p[1][cnt]++;
		if(c=='C')p[2][cnt]++;
		if(c=='H')p[3][cnt]++;
		if(c=='S')p[4][cnt]++;
	}

	for(int i=1;i<=4;i++){
		for(int k=1;k<=13;k++){
			if(!p[i][k])ans++;	
		}
	}


	cout << ans <<'\n';

	return 0;
}
