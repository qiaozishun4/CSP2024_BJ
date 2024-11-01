#include<iostream>
#include<map>
using namespace std;
int n,a[4][20],ans;
map<char,int> mp;
string x;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.ans","w",stdout);
	cin>>n;
	mp['A']=1,mp['2']=2,mp['3']=3,mp['4']=4,mp['5']=5,mp['6']=6,mp['7']=7,mp['8']=8,mp['9']=9,mp['T']=10,mp['J']=11,mp['Q']=12,mp['K']=13;
	for (int i=1;i<=n;i++){
		cin>>x;
		if (x[0]=='D')
			a[0][mp[x[1]]]++;
		else if (x[0]=='C')
			a[1][mp[x[1]]]++;
		else if (x[0]=='H')
			a[2][mp[x[1]]]++;
		else if (x[0]=='S')
			a[3][mp[x[1]]]++;
	}
	for (int i=0;i<=3;i++){
		for (int j=1;j<=13;j++)
			if (a[i][j]>0)
				ans++;
	}
	cout<<52-ans;
	return 0;
}
