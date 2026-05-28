/*
#include <iostream>
#include <string>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    _setmode(_fileno(stdout), _O_U8TEXT);

    wstring s{L"Не очень-то вежливо уходить из гостей сразу, как только ты наелся"};

    for (size_t i = 0; i < s.size(); i++) {
        if (s.find(s[i]) == s.rfind(s[i])) {
            wcout << s[i];
        }
    }
    wcout << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<float>> points(5);
    float min = 1e9;
    int index;
    float hsx, hsy, hsz;
    cin >> hsx >> hsy >> hsz;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        float n, x, y, z;
        cin >> n;
        points[0].push_back(n);
        cin >> x >> y >> z;
        points[1].push_back(x);
        points[2].push_back(y);
        points[3].push_back(z);
        points[4].push_back(sqrt(x*x + y*y + z*z));
        if (sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2)) < min) {
            min = sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2));
            index = i;
        }
    }
    cout << hsx - points[1][index] << " " << hsy - points[2][index] << " " << hsz - points[3][index] << "\n";
    cout << points[0][index];
    return 0;
    /*
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < num; j++) {
            cout << points[i][j] << " ";
        }
        cout << "\n";
    }
     */
}
