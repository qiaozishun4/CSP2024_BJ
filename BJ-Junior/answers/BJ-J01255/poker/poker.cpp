#include<bits/stdc++.h>
using namespace std;
int n;
string card;
int color,num;
int h[5][14];
int mapcolor[128],mapnum[128],ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    mapcolor['D']=1;mapcolor['C']=2;mapcolor['H']=3;mapcolor['S']=4;
    mapnum['A']=1;mapnum['2']=2;mapnum['3']=3;mapnum['4']=4;mapnum['5']=5;mapnum['6']=6;mapnum['7']=7;mapnum['8']=8;mapnum['9']=9;mapnum['T']=10;mapnum['J']=11;mapnum['Q']=12;mapnum['K']=13;
    ans=52;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>card;
        color=mapcolor[(int)card[0]];
        num=mapnum[(int)card[1]];
        if(h[color][num]==0)
        {
            h[color][num]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
