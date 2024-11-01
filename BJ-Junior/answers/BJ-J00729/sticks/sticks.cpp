#include<cstdio>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n,weishu;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        weishu=n/7;
        if (n%7==0) while(weishu--) putchar('8');
        else if (n%7==1)
        {
            if (n==1) putchar('-'),putchar('1'); else
            {
                weishu--,putchar('1'),putchar('0');
                while (weishu--) putchar('8');
            }
        }
        else if (n%7==2)
        {
            putchar('1');
            while (weishu--) putchar('8');
        }
        else if (n%7==3)
        {
            if (n==3) putchar('7'); else if (n==10) putchar('2'),putchar('2'); else
            {
                putchar('2'),putchar('0'),putchar('0'),weishu-=2;
                while (weishu--) putchar('8');
            }
        }
        else if (n%7==4)
        {
            if (n==4) putchar('4'); else
            {
                putchar('2'),putchar('0'),weishu--;
                while (weishu--) putchar('8');
            }
        }
        else if (n%7==5)
        {
            putchar('2');
            while (weishu--) putchar('8');
        }
        else if (n%7==6)
        {
            putchar('6');
            while (weishu--) putchar('8');
        }
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
