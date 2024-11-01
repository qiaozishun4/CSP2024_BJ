#include<bits/stdc++.h>
//#include<sys/kd.h>
using namespace std;

char s[52];int q =1, w =0;

string y;




string boom(char i, int t)
{

    s[1] = 'a';s[2] = 'b';s[3] = 'c';s[4] = 'd';s[5] = 'e';s[6] = 'f';s[7] = 'g';s[8] = 'h';s[9] = 'i';s[10] = 'j';s[11] = 'k';s[12] = 'l';s[13] = 'm';s[14] = 'n';s[15] = 'o';s[16] = 'p';s[17] = 'q';s[18] = 'r';s[19] = 's';s[20] = 't';s[21] = 'u';s[22] = 'v';s[23] = 'w';s[24] = 'x';s[25] = 'y';s[0] = 'a';
  //  cout << s[1] <<t-1;
    if(t==0)
    {
        cout << y;return "q";
    }

     double o = rand();
     //o*=;
     o/=100000;
     int d = int(o)%52;
     cout <<o ;
    char z =s[d];y+=z;
    cout << z <<endl <<endl;

    boom(z, t-1);
    return  y;

}








int main()
{
   // freopen("arena.in", "r", stdin);
   // freopen("arena.out", "w", stdout);
   int n;
   cin >>n;
    boom('a', n);

    return 0;

 //   fclose(stdin);
  //  fclose(stdout);
}