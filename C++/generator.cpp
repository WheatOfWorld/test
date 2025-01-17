#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int qpow(int num, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return num;
    }

    return qpow(num, exp / 2) * qpow(num, exp / 2) * (exp & 1 ? num : 1);
}

int main()
{
    string dataInput;
    cin >> dataInput;
    int testCount = (dataInput[0] - '0') * qpow(10, dataInput[2] - '0');
    vector<int> arr;
    for (int i = 1; i <= testCount; i++)
    {
        arr.emplace_back(i);
    }
    random_device rd;
    mt19937 mt(rd());
    shuffle(arr.begin(), arr.end(), mt);

    ofstream fileOut;
    fileOut.open("input.txt");
    for (auto i : arr)
    {
        fileOut << i << '\n';
    }
    fileOut.close();

    return 0;
}
