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

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float points[5][10];
    float min = 1e9;
    float max = 0;
    int min_index;
    int max_index;
    float hsx, hsy, hsz;
    cin >> hsx >> hsy >> hsz;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        float n, x, y, z;
        cin >> n;
        points[0][i] = n;
        cin >> x >> y >> z;
        points[1][i] = x;
        points[2][i] = y;
        points[3][i] = z;
        points[4][i] = sqrt(x*x + y*y + z*z);
        if (sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2)) < min) {
            min = sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2));
            min_index = i;
        }
        if (sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2)) > max) {
            max = sqrt(pow(x - hsz, 2) + pow(y - hsy, 2) + pow(z - hsz, 2));
            max_index = i;
        }
    }
    cout << hsx - points[1][min_index] << " " << hsy - points[2][min_index] << " " << hsz - points[3][min_index] << "\n";
    cout << points[0][min_index];
    
    float dx = points[1][max_index] - hsx;
    float dy = points[2][max_index] - hsy;
    float dz = points[3][max_index] - hsz;
    
    float hsx_t = hsx + 2 * dx;
    float hsy_t = hsy + 2 * dy;
    float hsz_t = hsz + 2 * dz;
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

