#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int> mp;
    for (int i = 0 ; i < nums.size() ; i++)
    {
        if (mp[nums[i]]) mp[nums[i]]++;
        else mp[nums[i]] = 1;
    }
    if (mp.size() > nums.size() / 2) return nums.size() / 2;
    else return mp.size();
}