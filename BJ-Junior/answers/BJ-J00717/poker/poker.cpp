#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int caohua[14] = {};
    int fangpian[14] = {};
    int hongtao[14] = {};
    int heitao[14] = {};
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin>>s;
        if(s[0] == 'D')
        {
            if(s[1] >= '2' && s[1] <= '9')
            {
                fangpian[s[1]-'0']++;
            }
            else if(s[1] == 'T')
            {
                fangpian[10]++;
            }
            else if(s[1] == 'A')
            {
                fangpian[1]++;
            }
            else if(s[1] == 'J')
            {
                fangpian[11]++;
            }
            else if(s[1] == 'Q')
            {
                fangpian[12]++;
            }
            else
            {
                fangpian[13]++;
            }
        }
        else if(s[0] == 'C')
        {
            if(s[1] >= '2' && s[1] <= '9')
            {
                caohua[s[1]-'0']++;
            }
            else if(s[1] == 'T')
            {
                caohua[10]++;
            }
            else if(s[1] == 'A')
            {
                caohua[1]++;
            }
            else if(s[1] == 'J')
            {
                caohua[11]++;
            }
            else if(s[1] == 'Q')
            {
                caohua[12]++;
            }
            else
            {
                caohua[13]++;
            }
        }
        else if(s[0] == 'H')
        {
            if(s[1] >= '2' && s[1] <= '9')
            {
                hongtao[s[1]-'0']++;
            }
            else if(s[1] == 'T')
            {
                hongtao[10]++;
            }
            else if(s[1] == 'A')
            {
                hongtao[1]++;
            }
            else if(s[1] == 'J')
            {
                hongtao[11]++;
            }
            else if(s[1] == 'Q')
            {
                hongtao[12]++;
            }
            else
            {
                hongtao[13]++;
            }
        }
        else
        {
            if(s[1] >= '2' && s[1] <= '9')
            {
                heitao[s[1]-'0']++;
            }
            else if(s[1] == 'T')
            {
                heitao[10]++;
            }
            else if(s[1] == 'A')
            {
                heitao[1]++;
            }
            else if(s[1] == 'J')
            {
                heitao[11]++;
            }
            else if(s[1] == 'Q')
            {
                heitao[12]++;
            }
            else
            {
                heitao[13]++;
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 13;i++)
    {
        if(fangpian[i] == 0)
        {
            cnt++;
        }
        if(caohua[i] == 0)
        {
            cnt++;
        }
        if(hongtao[i] == 0)
        {
            cnt++;
        }
        if(heitao[i] == 0)
        {
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
