#include<ostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;
map<string,int>m;
ifstream cin("poker.in");
ofstream cout("poker.out");
int main()
{
	int n;cin>>n;
	string str;
	while(cin>>str)m[str]++;
	cout<<52-m.size();
	cin.clear();
        return 0;
}