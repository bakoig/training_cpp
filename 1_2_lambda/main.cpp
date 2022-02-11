#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> vec{1,3,5,7,9,2,4,6,8,0};
    auto print = [](int x) { cout << x << endl; };
    for_each(vec.begin(), vec.end(), print);

    sort(vec.begin(), vec.end(), [](int x, int y) { return x < y; });
    for_each(vec.begin(), vec.end(), print);

    return 0;
}