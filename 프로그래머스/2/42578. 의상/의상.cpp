#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> mp;
    
    for (const auto& item : clothes)
    {
        mp[item[1]]++;
    }
    
    int answer = 1;
    
    for (const auto& pair : mp)
    {
        answer *= pair.second + 1;
    }
    return answer -1;
    
    
    
    
}