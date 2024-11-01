#include <iostream>

using namespace std;
bool xibao[262144];
int gongneng[262144];
int shuliang;
long long fenhua(bool DNA,int cishu)
{
    if(cishu>shuliang)
    {
        long long ans=0;
        for(int a=shuliang;a>0;a--)
        {
            for(int b=a-1;b>0;b--)
            {
                if(xibao[b]==xibao[a]&&gongneng[b]==gongneng[a])
                {
                    ans+=gongneng[b];
                    break;
                }
            }
        }
        return ans;
    }
    xibao[cishu]=DNA;
    return max(fenhua(0,cishu+1),fenhua(1,cishu+1));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>shuliang;
        for(int j=1;j<=shuliang;j++)
        {
            cin>>gongneng[j];
        }
        cout<<max(fenhua(0,1),fenhua(1,1))<<endl;
    }
    return 0;
}
