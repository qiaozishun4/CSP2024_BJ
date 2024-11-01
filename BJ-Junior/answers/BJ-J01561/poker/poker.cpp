#include<iostream>
#include<map>
using namespace std;
map<string,int> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    int k=m.size();
    cout<<(52-k)<<"\n";
    return 0;
}