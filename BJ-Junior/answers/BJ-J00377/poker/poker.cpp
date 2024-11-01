#include<iostream>
#include<map>
using namespace std;
map<string,int>m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt = 52;
    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(m[s] == 0)
        {
            m[s]++;
            cnt--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}