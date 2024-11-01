#include<bits/stdc++.h>
using namespace std;



int main()
{
    freopen("poker.in", "r",stdin);
    freopen("poker.out", "w",stdout);

    int n, a[114514];
    char c[100][999];
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >>s;
        if(s[0]=='D')
        {

            if(s[1]=='A')
            {
                a[1]++;
            }
            else if(s[1]=='2')
            {
                a[2]++;
            }

            else if(s[1]=='3')
            {
                a[3]++;
            }
            else if(s[1]=='4')
            {
                a[4]++;
            }
            else if(s[1]=='5')
            {
                a[5]++;
            }
            else if(s[1]=='6')
            {
                a[6]++;
            }
            else if(s[1]=='7')
            {
                a[7]++;
            }
            else if(s[1]=='8')
            {
                a[8]++;
            }
            else if(s[1]=='9')
            {
                a[9]++;
            }
            else if(s[1]=='T')
            {
                a[10]++;
            }
            else if(s[1]=='J')
            {
                a[11]++;
            }
            else if(s[1]=='Q')
            {
                a[12]++;
            }
            else
            {
                a[13]++;

            }


        }
        else if(s[0]=='C')
        {

            if(s[1]=='A')
            {
                a[14]++;
            }
            else if(s[1]=='2')
            {
                a[15]++;
            }

            else if(s[1]=='3')
            {
                a[16]++;
            }
            else if(s[1]=='4')
            {
                a[17]++;
            }
            else if(s[1]=='5')
            {
                a[18]++;
            }
            else if(s[1]=='6')
            {
                a[19]++;
            }
            else if(s[1]=='7')
            {
                a[20]++;
            }
            else if(s[1]=='8')
            {
                a[21]++;
            }
            else if(s[1]=='9')
            {
                a[22]++;
            }
            else if(s[1]=='T')
            {
                a[23]++;
            }
            else if(s[1]=='J')
            {
                a[24]++;
            }
            else if(s[1]=='Q')
            {
                a[25]++;
            }
            else
            {a[26]++;
            }


        }
         else if(s[0]=='H')
        {

            if(s[1]=='A')
            {
                a[27]++;
            }
            else if(s[1]=='2')
            {
                a[28]++;
            }

            else if(s[1]=='3')
            {
                a[29]++;
            }
            else if(s[1]=='4')
            {
                a[30]++;
            }
            else if(s[1]=='5')
            {
                a[31]++;
            }
            else if(s[1]=='6')
            {
                a[32]++;
            }
            else if(s[1]=='7')
            {
                a[33]++;
            }
            else if(s[1]=='8')
            {
                a[34]++;
            }
            else if(s[1]=='9')
            {
                a[35]++;
            }
            else if(s[1]=='T')
            {
                a[36]++;
            }
            else if(s[1]=='J')
            {
                a[37]++;
            }
            else if(s[1]=='Q')
            {
                a[38]++;
            }
            else {
                a[39]++;
            }
        }
        else
        {

            if(s[1]=='A')
            {
                a[40]++;
            }
            else if(s[1]=='2')
            {
                a[41]++;
            }

            else if(s[1]=='3')
            {
                a[42]++;
            }
            else if(s[1]=='4')
            {
                a[43]++;
            }
            else if(s[1]=='5')
            {
                a[44]++;
            }
            else if(s[1]=='6')
            {
                a[45]++;
            }
            else if(s[1]=='7')
            {
                a[46]++;
            }
            else if(s[1]=='8')
            {
                a[47]++;
            }
            else if(s[1]=='9')
            {
                a[48]++;
            }
            else if(s[1]=='T')
            {
                a[49]++;
            }
            else if(s[1]=='J')
            {
                a[50]++;
            }
            else if(s[1]=='Q')
            {
                a[51]++;
            }
            else
            {
                a[52]++;
            }
        }



    }
    int tot=52;
    for(int i = 1;i<=52;i++)
    {

        if(a[i])
        {
            tot--;
        }

    }
    cout <<tot;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
