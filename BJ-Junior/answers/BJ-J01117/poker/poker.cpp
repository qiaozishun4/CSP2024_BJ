#include <bits/stdc++.h>
using namespace std;
set<string>s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		string p;
			cin >>p;
		if((p[0]=='D'||p[0]=='C'||p[0]=='H'||p[0]=='S')&&(p[1]=='A'||p[1]=='2'||p[1]=='3'||p[1]=='4'||p[1]=='5'||p[1]=='6'||p[1]=='7'||p[1]=='8'||p[1]=='9'||p[1]=='T'||p[1]=='J'||p[1]=='Q'||p[1]=='K'))	s.insert(p);
	}
	cout <<52-s.size();
	return 0;
}
