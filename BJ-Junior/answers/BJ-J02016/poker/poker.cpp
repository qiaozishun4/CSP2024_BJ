#include<bits/stdc++.h>
using namespace std;
string s="DAD2D3D4D5D6D7D8D9DTDJDQDKCAC2C3C4C5C6C7C8C9CTCJCQCKHAH2H3H4H5H6H7H8H9HTHJHQHKSAS2S3S4S5S6S7S8S9STSJSQSK";
string s2;
int n,a,p;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poke.out","w",stdout);
    scanf("%d",&n);
    int i,c=0;
    for(i=1;i<=n;i++)
    {
        cin>>s2;
        if(s.find(s2)!=-1)
        {
            p=s.find(s2);
            c++;
            s.erase(p,2);
        }
    }
    printf("%d",52-c);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
