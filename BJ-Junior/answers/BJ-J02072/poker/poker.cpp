#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string s;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>s;
        bool f=1;
        for(int i=0;i<v.size();i++){
            if(v[i]==s){
                f=0;
                break;
            }
        }
        if(f){
            v.push_back(s);
        }
	}
	cout<<52-v.size();
    return 0;
}
