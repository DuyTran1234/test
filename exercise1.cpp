/*
    Cho dãy số tự nhiên A. Cài đặt chương trình sắp xếp dãy số A từ nhỏ đến lớn và loại bỏ số không phải là số nguyên tố.
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> getSieve(int n)
{
    std::vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
};
std::vector<int> exec(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int last = arr[arr.size() - 1];
    std::vector<bool> sieve = getSieve(last);
    std::vector<int> cloneArr;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (!sieve[arr[i]])
        {
            cloneArr.push_back(arr[i]);
        }
    }
    return cloneArr;
};
void display(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << "\n";
    }
}

int main()
{
    std::vector<int> list{0, 1, 2, 3, 4, 5, 8, 1, 2};
    list = exec(list);
    display(list);
}