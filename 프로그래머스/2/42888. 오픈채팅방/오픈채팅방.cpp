#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> userDB;
    for (int i = 0 ; i < record.size() ; i++)
    {
        string input = record[i];
        stringstream ss(input);
        
        string Function, ID, Name;
        ss >> Function >> ID ;
        if (Function != "Leave")
        {
            ss >> Name;
            userDB[ID] = Name;
        }   
    }
    for (int i = 0 ; i < record.size() ; i++)
    {
        string input = record[i];
        stringstream ss(input);
        
        string Function, ID, Name;
        ss >> Function >> ID ;
        if (Function == "Enter")
        {
            ss >> Name;
            string fin = userDB[ID] + "님이 들어왔습니다.";
            answer.push_back(fin);
        }
        else if (Function == "Leave")
        {
            string fin = userDB[ID] + "님이 나갔습니다.";
            answer.push_back(fin);
        }
        
    }
    
    return answer;
}