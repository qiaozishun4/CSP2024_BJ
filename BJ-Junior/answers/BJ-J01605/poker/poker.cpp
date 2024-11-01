#include<bits/stdc++.h>;
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    const int MAXN=52;
    int poker=52;
    bool flag=true;
    int color[MAXN];
    int number[MAXN];
    int num;
    char le,l;
    cin>>num;
    for(int i=1; i<=num; i++)
    {
        cin>>le>>l;
        for(int j=1; j<=i; j++)
        {
            if('le'==color[j]&&'l'==number[j]) flag=false;
        }
        if(flag)
        {
            poker--;
            color[i]='le';
            number[i]='l';
        }
    }
    cout<<poker<<endl;
    return 0;
}
