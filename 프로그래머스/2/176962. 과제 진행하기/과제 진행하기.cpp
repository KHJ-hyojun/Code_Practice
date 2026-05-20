#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Task {
    string name;
    int start_time;
    int play_time;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> result;
    vector<Task> tasks(plans.size());
    
    for (int i = 0 ; i < plans.size() ; i++)
    {
        tasks[i].name = plans[i][0];
        int time = stoi(plans[i][1].substr(0,2)) * 60 + stoi(plans[i][1].substr(3,2));
        tasks[i].start_time = time;
        tasks[i].play_time = stoi(plans[i][2]);
    }
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.start_time < b.start_time;
    });
    
    stack<pair<string,int>> st;
    
    int current_time ;
    
    for (int i = 0 ; i < tasks.size() ; i++)
    {
        if (i == tasks.size() - 1)
        {
            result.push_back(tasks[i].name);
            break;
        }
        
        current_time = tasks[i].start_time;
        if (current_time + tasks[i].play_time > tasks[i+1].start_time)
        {
            st.push({tasks[i].name,current_time + tasks[i].play_time - tasks[i+1].start_time});
        }
        else 
        {
            result.push_back(tasks[i].name);
            int remain_time = tasks[i+1].start_time - (current_time + tasks[i].play_time);
            while (!st.empty() && remain_time > 0)
            {
                auto top = st.top();
                st.pop();
                
                if (top.second <= remain_time )
                {
                    remain_time -= top.second;
                    result.push_back(top.first);
                }
                else
                {
                    st.push({top.first, top.second - remain_time});
                    remain_time = 0;
                }
            }
        }
    }
    while (!st.empty())
    {
        result.push_back(st.top().first);
        st.pop();
    }
    return result;
}