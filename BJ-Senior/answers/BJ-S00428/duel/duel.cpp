#include <fstream>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin ("duel.in");
ofstream cout ("duel.out");
const int MAXN = 1e5+10;
int a[MAXN];
multiset<int> s;
int main ()
{
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (s.size() and *s.begin()<a[i])
        {
            s.erase(s.begin());
        }
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
}