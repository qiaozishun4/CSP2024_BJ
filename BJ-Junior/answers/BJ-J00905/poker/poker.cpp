#include "bits/stdc++.h"
using namespace std;
map<string,int> p;
int n, ans;

void ch(string x){
	for(int i = 1;i <= 13;i++)
	{
		string c;
		if(i == 1)	c = 'A';
		if(i == 2)	c = '2';
		if(i == 3)	c = '3';
		if(i == 4)	c = '4';
		if(i == 5)	c = '5';
		if(i == 6)	c = '6';
		if(i == 7)	c = '7';
		if(i == 8)	c = '8';
		if(i == 9)	c = '9';
		if(i == 10)	c = 'T';
		if(i == 11)	c = 'J';
		if(i == 12)	c = 'Q';
		if(i == 13) c = 'K';
		string t = x + c;
		if(p[t] == 0)	ans++;
	}
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string t;
		cin >> t;
		p[t] = 1;
	}
	ch("D");
	ch("C");
	ch("H");
	ch("S");
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
