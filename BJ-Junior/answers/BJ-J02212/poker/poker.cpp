#include <bits/stdc++.h>

using namespace std;

bool p[60];
int n,ans=0;

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(p,false,sizeof(p));
    cin >> n;
    for(int i=1;i<=n;i++) {
        char op,c;
        cin >> op >> c;
        int x=-1;
        if(op == 'D')
			x+=1;
		else if(op == 'C')
			x+=14;
		else if(op == 'H')
			x+=27;
		else if(op == 'S')
			x+=40;

		if(c=='A')
			x+=1;
		else if(c == 'T')
			x+=10;
		else if(c == 'J')
			x+=11;
		else if(c == 'Q')
			x+=12;
		else if(c == 'K')
			x+=13;
		else
			x+=(c-'0');
		p[x] = true;
    }
    for(int i=1;i<=52;i++)
		if(p[i]==false)
			ans++;
	cout << ans << endl;

    return 0;
}
