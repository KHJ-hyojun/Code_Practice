#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    
    int result = 0;
    
    for (int i = m -1 ; i < score.size() ; i += m)
    {
        result += score[i] * m;
    }
    
    return result;
}