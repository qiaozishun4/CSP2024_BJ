#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    short n;
    scanf("%hd",&n);
    if (n==1)
    {
		cout<<51;
		return 0;
	}
    set<short> p;
    for(int i=0;i<n;i++)
    {
		char cur[2];
		scanf("%s",cur);
		p.insert((short)cur[0]*100+(short)cur[1]);
		
		
	}
	cout<<52-p.size();


    return 0;
}