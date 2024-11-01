#include <iostream>
using namespace std;
const int N=2e5+5;
int T7;
int allnums[N];
int graph[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T7;
    while(T7--)
    {
        int notch;
        cin>>notch;
        long long ans=0;
        int cur;
        for(int i=1;i<=200000;i++)
        {
            graph[i]=0;
        }
        for(int i=1;i<=notch;i++)
        {
            cin>>cur;
            graph[cur]++;
        }
        for(int i=1;i<=200000;i++)
        {
            if(graph[i]>=2)ans=ans+i*(graph[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
