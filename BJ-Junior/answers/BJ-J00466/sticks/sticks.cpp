#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int c[15] = {6,2,5,5,4,5,6,3,7,6};
string maxn = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

string match(string a,string b) //small one
{
    if(a.size() < b.size())
        return a;
    else if(a.size() > b.size())
        return b;
    for(int i = 0;i <= b.size();i++)
    {
        if(a[i] == b[i]) continue;
        else if(a[i] < b[i]) return a;
        else return b;
    }
    return a;
}

void dfs(int n,string s)
{
    if(n == 0)
    {
 //       cout << s << endl;
        maxn = match(maxn,s);
        return ;
    }
    if(n < 0) return ;
    for(int i = 0;i <= 9;i++)
    {

        if(i == 0 && s == "") continue;
        if(i == 3 || i == 5)
            dfs(n - 5,s + '2');
        if(i == 6 || i == 9)
        {
            if(s == "") dfs(n - 6,s +'6');
            else dfs(n - 6,s + '0');
        }
        char tmp = i + '0';
        dfs(n - c[i],s + tmp);
    }
}

int T;
int n;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    scanf("%d",&T);

    while(T--)
    {
        maxn = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
        scanf("%d",&n);
        if(n % 7 == 0)
        {
            for(int i = n;i >= 0;i-=7)
                printf("8");
            printf("\n");
            continue;
        }

        if(n % 7 == 1 && n != 1)
        {
            printf("10");
            for(int i = n;i >= 15;i-=7)
                printf("8");
            printf("\n");
            continue;
        }

        dfs(n,"");
        if(maxn == "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999")
            cout << -1 << endl;
        else cout << maxn << endl;
    }
    return 0;
}
