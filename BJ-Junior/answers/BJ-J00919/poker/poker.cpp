#include<bits/stdc++.h>
using namespace std;
string s[60],a[60]={"0","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
	"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK",
	"HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
	"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=52;i++)
	{
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==s[j]) flag=true;
		}
		if(!flag) ans++;
	}
	cout<<ans;
	return 0;
}