#include<algorithm>
#include<iostream>
#include<fstream>
#include<set>
using namespace std;
#define cin fin
#define cout fout
multiset<int> s;
int r[1000005];
int main()
{
	ifstream cin("duel.in");
	ofstream cout("duel.out");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		auto it=s.lower_bound(r[i]);
		if(it!=s.begin())
			--it,
//			cout<<r[i]<<" delete "<<*it<<endl,
			s.erase(it);
		s.emplace(r[i]);
	}
	cout<<s.size()<<endl;
}
