#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("poker.in","r",stdin);
    freopen ("poker.out","w",stdout);
    int a[52]={0};
    int n=0;
    int ps=0;
    int c;
    cin>>n;
    string have;
    for(int i=0;i<n;i++)
    {
        cin>>have;
        if(have=="DA")
            ps=1;
        if(have=="D2")
            ps=2;
        if(have=="D3")
            ps=3;
        if(have=="D4")
            ps=4;
        if(have=="D5")
            ps=5;
        if(have=="D6")
            ps=6;
        if(have=="D7")
            ps=7;
        if(have=="D8")
            ps=8;
        if(have=="D9")
            ps=9;
        if(have=="DT")
            ps=10;
        if(have=="DJ")
            ps=11;
        if(have=="DQ")
            ps=12;
        if(have=="DK")
            ps=13;
        if(have=="CA")
            ps=14;
        if(have=="C2")
            ps=15;
        if(have=="C3")
            ps=16;
        if(have=="C4")
            ps=17;
        if(have=="C5")
            ps=18;
        if(have=="C6")
            ps=19;
        if(have=="C7")
            ps=20;
        if(have=="C8")
            ps=21;
        if(have=="C9")
            ps=22;
        if(have=="CT")
            ps=23;
        if(have=="CJ")
            ps=24;
        if(have=="CQ")
            ps=25;
        if(have=="CK")
            ps=26;
        if(have=="SA")
            ps=27;
        if(have=="S2")
            ps=28;
        if(have=="S3")
            ps=29;
        if(have=="S4")
            ps=30;
        if(have=="S5")
            ps=31;
        if(have=="S6")
            ps=32;
        if(have=="S7")
            ps=33;
        if(have=="S8")
            ps=34;
        if(have=="S9")
            ps=35;
        if(have=="ST")
            ps=36;
        if(have=="SJ")
            ps=37;
        if(have=="SQ")
            ps=38;
        if(have=="SK")
            ps=39;
        if(have=="HA")
            ps=40;
        if(have=="H2")
            ps=41;
        if(have=="H3")
            ps=42;
        if(have=="H4")
            ps=43;
        if(have=="H5")
            ps=44;
        if(have=="H6")
            ps=45;
        if(have=="H7")
            ps=46;
        if(have=="H8")
            ps=47;
        if(have=="H9")
            ps=48;
        if(have=="HT")
            ps=49;
        if(have=="HJ")
            ps=50;
        if(have=="HQ")
            ps=51;
        if(have=="HK")
            ps=52;
        a[ps]=1;
    }
    for(int j=0;j<52;j++)
    {
        if(a[j]==0)
            c++;
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
