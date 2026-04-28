#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n)
        return {-1};
    vector<int> answer;
    
    int x = s / n + 1;
    int minus = n - s % n;
    
    for (int i = 0 ; i < n ; i++)
    {
        if (minus != 0) 
        {
            answer.push_back(x - 1);
            minus--;
        }
        else
        {
            answer.push_back(x);
        }
    }
    return answer;
}