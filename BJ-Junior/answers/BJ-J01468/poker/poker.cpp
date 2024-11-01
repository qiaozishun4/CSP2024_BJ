#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string str[54] = {};
    for (int i = 0; i < n; ++i)
    {
        string str01;
        cin >> str01;
        bool flag = 0;
        for (int j = 0; j < i; ++j)
        {
            if (str01 == str[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) str[i] = str01;
    }
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] != "") ++num;
    }
    cout << (52-num) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
