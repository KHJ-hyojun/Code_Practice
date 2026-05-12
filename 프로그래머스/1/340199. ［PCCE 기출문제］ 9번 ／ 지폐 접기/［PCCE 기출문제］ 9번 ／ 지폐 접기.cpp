#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int w1 = wallet[0];
    int w2 = wallet[1];
    int b1 = bill[0];
    int b2 = bill[1];
    
    while (!((w1 >= b1 && w2 >= b2) || (w1 >= b2 && w2 >= b1)))
    {
        answer++;
        if (b1 > b2)
            b1 /= 2;
        else
            b2 /= 2;
    }
    
    return answer;
}