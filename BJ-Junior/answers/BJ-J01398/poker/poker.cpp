#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    bool poker[4][13]={{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0}};
    int num=0;
    int c=n;
    while(n--)
    {
        string t;
        cin>>t;
        if(t[0]=="D")
        {
            if(t[1]=="1")
            {
                poker[0][0]=1;
                if(poker[0][0]=0)
                    len++;
                continue;
            }
            if(t[1]=="2")
            {
                poker[0][1]=1;
                if(poker[0][1]=0)
                    len++;
                continue;
            }
            if(t[1]=="3")
            {
                poker[0][2]=1;
                if(poker[0][2]=0)
                    len++;
                continue;
            }
            if(t[1]=="4")
            {
                poker[0][3]=1;
                if(poker[0][3]=0)
                    len++;
                continue;
            }
            if(t[1]=="5")
            {
                poker[0][4]=1;
                if(poker[0][4]=0)
                    len++;
                continue;
            }
            if(t[1]=="6")
            {
                poker[0][5]=1;
                if(poker[0][5]=0)
                    len++;
                continue;
            }
            if(t[1]=="7")
            {
                poker[0][6]=1;
                if(poker[0][6]=0)
                    len++;
                continue;
            }
            if(t[1]=="8")
            {
                poker[0][7]=1;
                if(poker[0][7]=0)
                    len++;
                continue;
            }
            if(t[1]=="9")
            {
                poker[0][8]=1;
                if(poker[0][8]=0)
                    len++;
                continue;
            }
            if(t[1]=="T")
            {
                poker[0][9]=1;
                if(poker[0][9]=0)
                    len++;
                continue;
            }
            if(t[1]=="J")
            {
                poker[0][10]=1;
                if(poker[0][10]=0)
                    len++;
                continue;
            }
            if(t[1]=="Q")
            {
                poker[0][11]=1;
                if(poker[0][11]=0)
                    len++;
                continue;
            }
            if(t[1]=="K")
            {
                poker[0][12]=1;
                if(poker[0][12]=0)
                    len++;
                continue;
            }
        }
        if(t[0]=="C")
        {
            if(t[1]=="1")
            {
                poker[1][0]=1;
                if(poker[1][0]=0)
                    len++;
                continue;
            }
            if(t[1]=="2")
            {
                poker[1][1]=1;
                if(poker[1][1]=0)
                    len++;
                continue;
            }
            if(t[1]=="3")
            {
                poker[1][2]=1;
                if(poker[1][2]=0)
                    len++;
                continue;
            }
            if(t[1]=="4")
            {
                poker[1][3]=1;
                if(poker[1][3]=0)
                    len++;
                continue;
            }
            if(t[1]=="5")
            {
                poker[1][4]=1;
                if(poker[1][4]=0)
                    len++;
                continue;
            }
            if(t[1]=="6")
            {
                poker[1][5]=1;
                if(poker[1][5]=0)
                    len++;
                continue;
            }
            if(t[1]=="7")
            {
                poker[1][6]=1;
                if(poker[1][6]=0)
                    len++;
                continue;
            }
            if(t[1]=="8")
            {
                poker[1][7]=1;
                if(poker[1][7]=0)
                    len++;
                continue;
            }
            if(t[1]=="9")
            {
                poker[1][8]=1;
                if(poker[1][8]=0)
                    len++;
                continue;
            }
            if(t[1]=="T")
            {
                poker[1][9]=1;
                if(poker[1][9]=0)
                    len++;
                continue;
            }
            if(t[1]=="J")
            {
                poker[1][10]=1;
                if(poker[1][10]=0)
                    len++;
                continue;
            }
            if(t[1]=="Q")
            {
                poker[1][11]=1;
                if(poker[1][11]=0)
                    len++;
                continue;
            }
            if(t[1]=="K")
            {
                poker[1][12]=1;
                if(poker[1][12]=0)
                    len++;
                continue;
            }
        }
        if(t[0]=="S")
        {
            if(t[1]=="1")
            {
                poker[2][0]=1;
                if(poker[2][0]=0)
                    len++;
                continue;
            }
            if(t[1]=="2")
            {
                poker[2][1]=1;
                if(poker[2][1]=0)
                    len++;
                continue;
            }
            if(t[1]=="3")
            {
                poker[2][2]=1;
                if(poker[2][2]=0)
                    len++;
                continue;
            }
            if(t[1]=="4")
            {
                poker[2][3]=1;
                if(poker[2][3]=0)
                    len++;
                continue;
            }
            if(t[1]=="5")
            {
                poker[2][4]=1;
                if(poker[2][4]=0)
                    len++;
                continue;
            }
            if(t[1]=="6")
            {
                poker[2][5]=1;
                if(poker[2][5]=0)
                    len++;
                continue;
            }
            if(t[1]=="7")
            {
                poker[2][6]=1;
                if(poker[2][6]=0)
                    len++;
                continue;
            }
            if(t[1]=="8")
            {
                poker[2][7]=1;
                if(poker[2][7]=0)
                    len++;
                continue;
            }
            if(t[1]=="9")
            {
                poker[2][8]=1;
                if(poker[2][8]=0)
                    len++;
                continue;
            }
            if(t[1]=="T")
            {
                poker[2][9]=1;
                if(poker[2][9]=0)
                    len++;
                continue;
            }
            if(t[1]=="J")
            {
                poker[2][10]=1;
                if(poker[2][10]=0)
                    len++;
                continue;
            }
            if(t[1]=="Q")
            {
                poker[2][11]=1;
                if(poker[2][11]=0)
                    len++;
                continue;
            }
            if(t[1]=="K")
            {
                poker[2][12]=1;
                if(poker[2][12]=0)
                    len++;
                continue;
            }
        }
        if(t[0]=="H")
        {
            if(t[1]=="1")
            {
                poker[3][0]=1;
                if(poker[3][0]=0)
                    len++;
                continue;
            }
            if(t[1]=="2")
            {
                poker[3][1]=1;
                if(poker[3][1]=0)
                    len++;
                continue;
            }
            if(t[1]=="3")
            {
                poker[3][2]=1;
                if(poker[3][2]=0)
                    len++;
                continue;
            }
            if(t[1]=="4")
            {
                poker[3][3]=1;
                if(poker[3][3]=0)
                    len++;
                continue;
            }
            if(t[1]=="5")
            {
                poker[3][4]=1;
                if(poker[3][4]=0)
                    len++;
                continue;
            }
            if(t[1]=="6")
            {
                poker[3][5]=1;
                if(poker[3][5]=0)
                    len++;
                continue;
            }
            if(t[1]=="7")
            {
                poker[3][6]=1;
                if(poker[3][6]=0)
                    len++;
                continue;
            }
            if(t[1]=="8")
            {
                poker[3][7]=1;
                if(poker[3][7]=0)
                    len++;
                continue;
            }
            if(t[1]=="9")
            {
                poker[3][8]=1;
                if(poker[3][8]=0)
                    len++;
                continue;
            }
            if(t[1]=="T")
            {
                poker[3][9]=1;
                if(poker[3][9]=0)
                    len++;
                continue;
            }
            if(t[1]=="J")
            {
                poker[3][10]=1;
                if(poker[3][10]=0)
                    len++;
                continue;
            }
            if(t[1]=="Q")
            {
                poker[3][11]=1;
                if(poker[3][11]=0)
                    len++;
                continue;
            }
            if(t[1]=="K")
            {
                poker[3][12]=1;
                if(poker[3][12]=0)
                    len++;
                continue;
            }
        }
    }
    cout<<(c-len);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

