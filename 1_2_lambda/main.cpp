#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> vec{1,3,5,7,9,2,4,6,8,0};
    auto print = [](int x) { cout << x << " "; };
    for_each(vec.begin(), vec.end(), print);
    cout << endl;

    int cnt = 0;
    sort(vec.begin(), vec.end(), [&cnt](int x, int y) { if (x < y) {cnt++;}; return x < y; });
    for_each(vec.begin(), vec.end(), print);
    cout << cnt << endl;

    return 0;
}