#include <bits/stdc++.h>
using namespace std;
int n,len;
string l[200];
string w;
bool torf;
int main()
{
	freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin >> w;
		torf=true;
		for(int j=0;j<len;j++)
		{
			if(w==l[j])	{torf=false;break;}
		}
		if (torf) 
		{
			l[len]=w;
			len++;
		}
	}
	cout << 52-len;
	return 0;
} 