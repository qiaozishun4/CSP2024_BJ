#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    scanf("%d",&n);
    string ans = "";
    for(int i = 0;i < n; i++)
    {
            int st = 0;

        string aa;
        cin >> aa;
        for(int j = 0; j < i; j++)
        {
            if(ans.find(aa) != string::npos)
                st = 1;
        }
        if(st == 0)
            ans.append(aa);
    }
    cout << 52-((ans.size())/2);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
