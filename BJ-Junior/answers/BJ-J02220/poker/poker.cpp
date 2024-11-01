#include<bits/stdc++.h>
using namespace std;
bool a[60];
int e[128]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,1,0,2,1,0,0,0,3,0,11,13,0,0,0,0,0,12,0,4,10};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c,d;
        cin>>c>>d;
        a[(e[c]-1)*13+e[d]]=true;
    }
    int cnt=0;
    for(int i=1;i<=55;i++)
    {
        if(a[i])
        {
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}
