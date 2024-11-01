#include<bits/stdc++.h>
using namespace std;
map<char ,int> mp1,mp2,mp3,mp4;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int card = 0;
    for(int i = 1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        char x;
        cin>>x;
        if(ch == 'S')
        {
            if(mp1[x])
            {
                continue;
            }
            else
            {
                card++;
                mp1[x]++;
            }
        }
        if(ch == 'C')
        {
            if(mp2[x])
            {
                continue;
            }
            else
            {
                card++;
                mp2[x]++;
            }
        }
        if(ch == 'D')
        {
            if(mp3[x])
            {
                continue;
            }
            else
            {
                card++;
                mp3[x]++;
            }
        }
        if(ch == 'H')
        {
            if(mp4[x])
            {
                continue;
            }
            else
            {
                card++;
                mp4[x]++;
            }
        }
    }
    cout<<52-card<<endl;
    return 0;
}
