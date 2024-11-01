#include <fstream>
using namespace std;
ifstream cin("poker.in");
ofstream cout("poker.out");
char c1,c2;
int n,ans,f[10][20];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c1>>c2;
        if(c1=='D')
        {
            if(c2>='2'&&c2<='9')
                f[1][c2-'0']++;
            if(c2=='A')
                f[1][1]++;
            if(c2=='T')
                f[1][10]++;
            if(c2=='J')
                f[1][11]++;
            if(c2=='Q')
                f[1][12]++;
            if(c2=='K')
                f[1][13]++;
        }
        if(c1=='C')
        {
            if(c2>='2'&&c2<='9')
                f[2][c2-'0']++;
            if(c2=='A')
                f[2][1]++;
            if(c2=='T')
                f[2][10]++;
            if(c2=='J')
                f[2][11]++;
            if(c2=='Q')
                f[2][12]++;
            if(c2=='K')
                f[2][13]++;
        }
        if(c1=='H')
        {
            if(c2>='2'&&c2<='9')
                f[3][c2-'0']++;
            if(c2=='A')
                f[3][1]++;
            if(c2=='T')
                f[3][10]++;
            if(c2=='J')
                f[3][11]++;
            if(c2=='Q')
                f[3][12]++;
            if(c2=='K')
                f[3][13]++;
        }
        if(c1=='S')
        {
            if(c2>='2'&&c2<='9')
                f[4][c2-'0']++;
            if(c2=='A')
                f[4][1]++;
            if(c2=='T')
                f[4][10]++;
            if(c2=='J')
                f[4][11]++;
            if(c2=='Q')
                f[4][12]++;
            if(c2=='K')
                f[4][13]++;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(f[i][j]==0)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
