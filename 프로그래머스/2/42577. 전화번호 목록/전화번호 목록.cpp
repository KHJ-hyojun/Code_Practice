#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> um;
    for (const string& phone : phone_book)
    {
        um[phone] = true;
    }
    
    for (const string& phone : phone_book)
    {
        string prefix = "";
        for (int i = 0 ; i < phone.size() - 1 ; i++)
        {   
            prefix += phone[i];
            
            if (um.count(prefix)) 
            {
                return false;
            }
        }
    }
    return true;
    
}