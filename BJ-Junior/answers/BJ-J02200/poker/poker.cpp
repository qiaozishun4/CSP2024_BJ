#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map <string, int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    mp["DA"] = mp["DT"] = mp["DJ"] = mp["DQ"] = mp["DK"] = 0;
    mp["CA"] = mp["CT"] = mp["CJ"] = mp["CQ"] = mp["CK"] = 0;
    mp["HA"] = mp["HT"] = mp["HJ"] = mp["HQ"] = mp["HK"] = 0;
    mp["SA"] = mp["ST"] = mp["SJ"] = mp["SQ"] = mp["SK"] = 0;
    mp["D1"] = mp["D2"] = mp["D3"] = mp["D4"] = mp["D5"] = mp["D6"] = mp["D7"] = mp["D8"] = mp["D9"] = 0;
    mp["C1"] = mp["C2"] = mp["C3"] = mp["C4"] = mp["C5"] = mp["C6"] = mp["C7"] = mp["C8"] = mp["C9"] = 0;
    mp["H1"] = mp["H2"] = mp["H3"] = mp["H4"] = mp["H5"] = mp["H6"] = mp["H7"] = mp["H8"] = mp["H9"] = 0;
    mp["S1"] = mp["S2"] = mp["S3"] = mp["S4"] = mp["S5"] = mp["S6"] = mp["S7"] = mp["S8"] = mp["S9"] = 0;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        mp[s] = 1;
    }
    int ans = 0;
    if(mp["DA"]) ans++;
    if(mp["D1"]) ans++;
    if(mp["D2"]) ans++;
    if(mp["D3"]) ans++;
    if(mp["D4"]) ans++;
    if(mp["D5"]) ans++;
    if(mp["D6"]) ans++;
    if(mp["D7"]) ans++;
    if(mp["D8"]) ans++;
    if(mp["D9"]) ans++;
    if(mp["DT"]) ans++;
    if(mp["DJ"]) ans++;
    if(mp["DQ"]) ans++;
    if(mp["DK"]) ans++;

    if(mp["CA"]) ans++;
    if(mp["C1"]) ans++;
    if(mp["C2"]) ans++;
    if(mp["C3"]) ans++;
    if(mp["C4"]) ans++;
    if(mp["C5"]) ans++;
    if(mp["C6"]) ans++;
    if(mp["C7"]) ans++;
    if(mp["C8"]) ans++;
    if(mp["C9"]) ans++;
    if(mp["CT"]) ans++;
    if(mp["CJ"]) ans++;
    if(mp["CQ"]) ans++;
    if(mp["CK"]) ans++;

    if(mp["HA"]) ans++;
    if(mp["H1"]) ans++;
    if(mp["H2"]) ans++;
    if(mp["H3"]) ans++;
    if(mp["H4"]) ans++;
    if(mp["H5"]) ans++;
    if(mp["H6"]) ans++;
    if(mp["H7"]) ans++;
    if(mp["H8"]) ans++;
    if(mp["H9"]) ans++;
    if(mp["HT"]) ans++;
    if(mp["HJ"]) ans++;
    if(mp["HQ"]) ans++;
    if(mp["HK"]) ans++;

    if(mp["SA"]) ans++;
    if(mp["S1"]) ans++;
    if(mp["S2"]) ans++;
    if(mp["S3"]) ans++;
    if(mp["S4"]) ans++;
    if(mp["S5"]) ans++;
    if(mp["S6"]) ans++;
    if(mp["S7"]) ans++;
    if(mp["S8"]) ans++;
    if(mp["S9"]) ans++;
    if(mp["ST"]) ans++;
    if(mp["SJ"]) ans++;
    if(mp["SQ"]) ans++;
    if(mp["SK"]) ans++;
    cout << 52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
