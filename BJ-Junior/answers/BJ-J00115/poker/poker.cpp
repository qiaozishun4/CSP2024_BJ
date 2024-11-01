#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>
using namespace std;
set <string> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	long long int n=0;
	cin>>n;
	//cout<<"n="<<n<<endl;
	string s;
	for(long long int j1=1;j1<=n;j1++)
	{
		cin>>s;
		st.insert(s);
		//cout<<"n="<<n<<endl;
	}
	long long int len=st.size();
	//cout<<"len="<<len<<endl;
	long long int ans=52-len;
	cout<<ans;
    return 0;
}
