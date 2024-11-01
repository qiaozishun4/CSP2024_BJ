#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int zs;
    scanf("%d",&zs);
    for(int zsi = 0;zsi < zs;zsi ++)
    {
        //printf("##14\n");
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int x,y,d,b = 0,gl = 0;
        scanf("%d %d %d",&x,&y,&d);
        bool tu[1005][1005] = {{false}};
        bool bj[1005][1005] = {{false}};
        //printf("##21\n");
        for(int ti = 1;ti <= n;ti ++)
        {
            string _s;
            cin >> _s;
            for(int si = 1;si <= _s.size();si ++)
            {
                if(_s[si] == '.')
                    tu[ti][si] = true;
                else
                    tu[ti][si] = false;
            }
        }

        //for(int c_i = 0;c_i < 100;c_i ++)
        //{
        //    printf("###%d\n",(bj[c_i][c_i])? 1 : 0);
        //}
        //printf("##34 --%d\n",(bj[1][1])? 1 : 0);
        for(b = 0;b < k;b ++)
        {
            int _x = x,_y = y;
            switch(d)
            {
            case 0:
                {
                    _y ++;
                    break;
                }
            case 1:
                {
                    _x ++;
                    break;
                }
            case 2:
                {
                    _y --;
                    break;
                }
            case 3:
                {
                    _x --;
                    break;
                }
            }
            //printf("##end switch to %d %d tu %d\n",_x,_y,(tu[_x][_y]) ? 1 : 0);

            if(_x >= 1 && _x <= n && _y >= 1 && _y <= m && tu[_x][_y])
            {
                //printf("##run 1\n");
                x = _x;
                y = _y;
                //b ++;
                if(bj[x][y] == false)
                    gl ++;
                bj[x][y] = true;
            }
            else
            {
                //printf("##run 2\n");
                d ++;
                d %= 4;
                //b ++;
                bj[x][y] = true;
            }
        }

        printf("%d\n",gl);
    }
    return 0;
}
