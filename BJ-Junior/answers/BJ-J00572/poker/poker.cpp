#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#define fin freopen("poker.in","r",stdin);
#define fout freopen("poker.out","w",stdout);
using namespace std;
int n;
set<string> cards;
int main()
{
    fin
    fout
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        cards.insert(s);
    }
    cout << (52-cards.size()) << endl;
	return 0;
}
