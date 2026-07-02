#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> um;
    for (const string& name : participant)
    {
        um[name]++;
    }
    for (const string& name : completion)
    {
        um[name]--;
    }
    for (auto& pair : um)
    {
        if (pair.second > 0)
            return pair.first;
    }
    return "";
}