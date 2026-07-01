#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
   vector<int> result;
    result.push_back(arr[0]);
    for (int i = 1 ; i < arr.size() ; i++)
    {
        if (arr[i] != result.back()) result.push_back(arr[i]);
    }
    return result;
}
