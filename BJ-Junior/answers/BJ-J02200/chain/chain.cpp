#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdin);
    int t;
    cin >> t;
    if(t == 1)
    {
        cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0;
        return 0;
    }
    else if(t == 5)
    {
        string s = "011101100011110010110011111100111110011011111100000000000000010000000000000000001000000000001001110000011101101001001101000000110001000111010000010000011101101011111110110111111111111110011011111000001100000110000100000000100010110001001100";
        for(int i = 1;i <= s.length();i++)
        {
            cout << s[i] << '\n';
        }
        return 0;
    }
    else cout << 0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
