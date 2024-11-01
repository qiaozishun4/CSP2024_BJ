#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int n,cnt=52;
bool a[5][14];
map<char,int>chart;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(a,0,sizeof(a));
    chart['D']=1;
    chart['C']=2;
    chart['S']=3;
    chart['H']=4;
    chart['A']=1;
    chart['2']=2;
    chart['3']=3;
    chart['4']=4;
    chart['5']=5;
    chart['6']=6;
    chart['7']=7;
    chart['8']=8;
    chart['9']=9;
    chart['T']=10;
    chart['J']=11;
    chart['Q']=12;
    chart['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        //cout<<a[chart[s[0]]][chart[s[1]]]<<endl;
        if( !a[chart[s[0]]][chart[s[1]]] ){cnt--;}
        a[chart[s[0]]] [chart[s[1]]]=1;
    }
    cout<<cnt;
    return 0;
}
