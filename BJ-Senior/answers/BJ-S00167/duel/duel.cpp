#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
vector<pii> v;
int n;
long long l;
int a[100005];
map<int,int> s;
bool cmp(pii n1,pii n2)
{
    return n1.x < n2.x;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        s[a[i]]++;
    }
    for(auto i : s)
    {
        v.push_back(i);
    }
    sort(v.begin(),v.end(),cmp);
    l = v[0].y;
    for(int i = 1;i < v.size();i++)
    {
        if(v[i].y <= l) l = l;
        else l = v[i].y;
    }
    cout << l;
    return 0;
}