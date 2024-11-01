#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    map <string,bool> poker_cunzai;
    string all_kapai="A23456789TJQK";
    string all_huase="DCHS";
    cin >> n;
    for (int i=0;i<n;i++)
    {
        string temp_str="";
        char a,b;
        cin >> a >> b;
        temp_str+=a;
        temp_str+=b;
        poker_cunzai[temp_str]=1;
    }
    int ans=0;
    for (int kapai=0;kapai<13;kapai++)
    {
        for(int huase=0;huase<4;huase++)
        {
            string a;
            a+=all_huase[huase];
            a+=all_kapai[kapai];
            //string a=all_huase[huase]+all_kapai[kapai];
            if(!poker_cunzai[a])
            {
                ans++;

            }
        }
    }

    cout << ans << endl;
}