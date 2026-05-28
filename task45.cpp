#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    for (int i = 1; i < 28; i++) {  
    printf("%f\n", pow(-1, i) / (i * (i + 1) * (i + 2)));
    }
    float u = -1e5;
    printf("/\n");
    float j = 0;
    for (int i = 1; i < 26; i++) {
        j = 5*sqrt(i)*cos(0.9 * i);
        if (u < j) u = j;
    }
    printf("%f\n/\n", u);
    float sum = 0;
    int i = 0;
    float fact = i + 1;
    while (sum + pow(2, 2*i + 1) / ((2*i + 1) * fact) != sum) {
        sum += pow(2, 2*i + 1) / ((2*i + 1) * fact);
        i++;
        fact = fact * (i + 1);
    }
    printf("%f\n/\n", sum);
    vector<float> a = {0.0, 0.1};
    i = 1;
    float min = 1e5; 
    do {
        a.push_back(sin(a[i]) + a[i - 1]);
        if (a[i + 1] < min) min = a[i + 1];
        i++;
    } while(a[i] <= 5.0);
    printf("%f\n", min);
    return 0;
}
