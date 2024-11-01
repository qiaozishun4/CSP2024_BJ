#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string str;
map<string,bool> book;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>str;
        if(book[str])
        {
            continue;
        }
        book[str]=1;
        cnt++;
    }
    cout<<52-cnt;
    return 0;
}
