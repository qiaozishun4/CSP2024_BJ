#include<bits/stdc++.h>
using namespace std;
long long ans;
void fin(int x,long long y)
{
    //cout<<x<<" "<<y<<" "<<ans<<endl;
    if(x==0&&((y<ans&&y>0)||(ans==-1&&y!=0)))
        ans=y;
    if(x<=1||(y>ans&&ans!=-1))
        return ;
    if(y!=0)
        fin(x-6,y*10);
    fin(x-2,y*10+1);
    fin(x-5,y*10+2);
    //fin(x-5,y*10+3);
    fin(x-4,y*10+4);
    //fin(x-5,y*10+5);
    fin(x-6,y*10+6);
    fin(x-3,y*10+7);
    fin(x-7,y*10+8);
    //fin(x-6,y*10+9);
}
int main()
{

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ans=-1;
        fin(n,0);
        cout<<ans<<endl;
    }
    return 0;
}

