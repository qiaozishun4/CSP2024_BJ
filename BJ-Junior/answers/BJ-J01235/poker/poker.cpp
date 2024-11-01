#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int a[52];
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="DA")  a[i]=1;
        else if(str=="D2") a[i]=2;
        else if(str=="D3") a[i]=3;
        else if(str=="D4") a[i]=4;
        else if(str=="D5") a[i]=5;
        else if(str=="D6") a[i]=6;
        else if(str=="D7") a[i]=7;
        else if(str=="D8") a[i]=8;
        else if(str=="D9") a[i]=9;
        else if(str=="DT") a[i]=10;
        else if(str=="DJ") a[i]=11;
        else if(str=="DQ") a[i]=12;
        else if(str=="DK") a[i]=13;
        else if(str=="CA") a[i]=14;
        else if(str=="C2") a[i]=15;
        else if(str=="C3") a[i]=16;
        else if(str=="C4") a[i]=17;
        else if(str=="C5") a[i]=18;
        else if(str=="C6") a[i]=19;
        else if(str=="C7") a[i]=20;
        else if(str=="C8") a[i]=21;
        else if(str=="C9") a[i]=22;
        else if(str=="CT") a[i]=23;
        else if(str=="CJ") a[i]=24;
        else if(str=="CQ") a[i]=25;
        else if(str=="CK") a[i]=26;
        else if(str=="HA") a[i]=27;
        else if(str=="H2") a[i]=28;
        else if(str=="H3") a[i]=29;
        else if(str=="H4") a[i]=30;
        else if(str=="H5") a[i]=31;
        else if(str=="H6") a[i]=32;
        else if(str=="H7") a[i]=33;
        else if(str=="H8") a[i]=34;
        else if(str=="H9") a[i]=35;
        else if(str=="HT") a[i]=36;
        else if(str=="HJ") a[i]=37;
        else if(str=="HQ") a[i]=38;
        else if(str=="HK") a[i]=39;
        else if(str=="SA") a[i]=40;
        else if(str=="S2") a[i]=41;
        else if(str=="S3") a[i]=42;
        else if(str=="S4") a[i]=43;
        else if(str=="S5") a[i]=44;
        else if(str=="S6") a[i]=45;
        else if(str=="S7") a[i]=46;
        else if(str=="S8") a[i]=47;
        else if(str=="S9") a[i]=48;
        else if(str=="ST") a[i]=49;
        else if(str=="SJ") a[i]=50;
        else if(str=="SQ") a[i]=51;
        else if(str=="SK") a[i]=52;
    }
    sort(a,a+n);
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1]) ans++;
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
