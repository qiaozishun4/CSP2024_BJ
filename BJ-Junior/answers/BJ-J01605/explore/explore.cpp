#include<bits/stdc++.h>;
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    const int MAXN=1001;
    char ma[MAXN][MAXN];
    int num[6];
    int time,n,m,k,x,y,d;
    int number=1;
    cin>>time;
    /*
    假设机器人当前处在的位置为 (x, y),朝向为 d。则它的方向上的下一步的位
置 (x ′ , y ′ ) 定义如下:若 d = 0,则令 (x ′ , y ′ ) = (x, y + 1),若 d = 1,则令
(x ′ , y ′ ) = (x + 1, y),若 d = 2,则令 (x ′ , y ′ ) = (x, y − 1),若 d = 3,则令
(x ′ , y ′ ) = (x − 1, y)。
2. 接下来,机器人判断它下一步的位置是否在地图内,且是否为空地。具体地说,
它判断 (x ′ , y ′ ) 是否满足 1 ≤ x ′ ≤ n, 1 ≤ y ′ ≤ m,且 (x ′ , y ′ ) 位置上是空地。如果
条件成立,则机器人会向前走一步。它新的位置变为 (x ′ , y ′ ),且朝向不变。如果
条件不成立,则它会执行“向右转”操作。也就是说,令 d ′ = (d + 1) mod 4(即
d + 1 除以 4 的余数),且它所处的位置保持不变,但朝向由 d 变为 d ′ 。

    */
    for(int i=1;i<=time;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int g=1;g<=m;g++)
            {
                cin>>ma[n][m];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if((d==0&&y+1<=m)||(d==1&&x+1<=n)||(d==2&&x-1>=1)||(d==3&&y-1>=1))
            {
                if(d==0) y++;
                if(d==1) x++;
                if(d==2) x--;
                if(d==3) y--;
                number++;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        num[i]=number;
    }
    for(int i=1;i<=time;i++)
    {
        cout<<num[i]<<endl;
    }
    return 0;
}
