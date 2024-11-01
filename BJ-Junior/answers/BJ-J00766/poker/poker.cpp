#include<bits/stdc++.h>
using namespace std;
string s;
map<string,int>hsh;
int n,cnt[53],ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	hsh["DA"] = 1;
	hsh["D2"] = 2;
	hsh["D3"] = 3;
	hsh["D4"] = 4;
	hsh["D5"] = 5;
	hsh["D6"] = 6;
	hsh["D7"] = 7;
	hsh["D8"] = 8;
	hsh["D9"] = 9;
	hsh["DT"] = 10;
	hsh["DJ"] = 11;
	hsh["DQ"] = 12;
	hsh["DK"] = 13;
	hsh["CA"] = 14;
	hsh["C2"] = 15;
	hsh["C3"] = 16;
	hsh["C4"] = 17;
	hsh["C5"] = 18;
	hsh["C6"] = 19;
	hsh["C7"] = 20;
	hsh["C8"] = 21;
	hsh["C9"] = 22;
	hsh["CT"] = 23;
	hsh["CJ"] = 24;
	hsh["CQ"] = 25;
	hsh["CK"] = 26;
	hsh["HA"] = 27;
	hsh["H2"] = 28;
	hsh["H3"] = 29;
	hsh["H4"] = 30;
	hsh["H5"] = 31;
	hsh["H6"] = 32;
	hsh["H7"] = 33;
	hsh["H8"] = 34;
	hsh["H9"] = 35;
	hsh["HT"] = 36;
	hsh["HJ"] = 37;
	hsh["HQ"] = 38;
	hsh["HK"] = 39;
	hsh["SA"] = 40;
	hsh["S2"] = 41;
	hsh["S3"] = 42;
	hsh["S4"] = 43;
	hsh["S5"] = 44;
	hsh["S6"] = 45;
	hsh["S7"] = 46;
	hsh["S8"] = 47;
	hsh["S9"] = 48;
	hsh["ST"] = 49;
	hsh["SJ"] = 50;
	hsh["SQ"] = 51;
	hsh["SK"] = 52;
	cin>>n;
	while(n--)
	{
		cin>>s;
		cnt[hsh[s]]++;
	}
	for(int i = 1;i<=52;i++)
	{
		if(cnt[i] == 0)ans++;
	}
	cout<<ans;
}