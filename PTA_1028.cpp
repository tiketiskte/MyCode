/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS{ios::sync_with_stdio(false); cin.tie(0);}
#define INF 0x3f3f3f3f

/* const int maxn = 1e5 + 5; */
using namespace std;
int n;

int main()
{
    IOS 
    int cnt = 0;
    cin >> n;
    string minbirth = "2014/09/06", maxbirth = "1814/09/06";
    string minname = "", maxname = "";
    string temp_name = "", temp_birth = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> temp_name >> temp_birth;
        if (temp_birth >= "1814/09/06" && temp_birth <= "2014/09/06")
        {
            cnt++;
            if (temp_birth >= maxbirth)
            {
                maxname = temp_name;
                maxbirth = temp_birth;
            }
            if (temp_birth <= minbirth)
            {
                minname = temp_name;
                minbirth = temp_birth;
            }
        }
    }
    cout << cnt << " ";
    if (cnt != 0)
    {
        cout << minname << " " << maxname << endl;
    }
    //system("pause");
    return 0;
}
