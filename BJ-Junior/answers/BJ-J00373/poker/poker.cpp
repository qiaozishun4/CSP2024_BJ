#include<iostream>
using namespace std;
string s[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,cur=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        string a;
        cin >>a;
        bool flag=1;
        for (int j=1;j<=cur;j++)
        {
            if (s[j]==a){flag=0;break;}
        }
        if (flag)
        {
            s[++cur]=a;
        }
    }
    cout << 52-cur << endl;
    return 0;
}
