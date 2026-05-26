#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int success_time = 0;
    int attack_cnt = 0;
    int my_health = health;
    int last_attack = attacks[attacks.size() - 1][0];
    
    for (int i = 1 ; i <= last_attack ; i++)
    {
        if (attacks[attack_cnt][0] == i)
        {
            my_health -= attacks[attack_cnt][1];
            if (my_health <= 0) return -1;
            attack_cnt++;
            success_time = 0;
        }
        else 
        {
            my_health += bandage[1];
            success_time++;
            
            if (success_time == bandage[0])
            {
                my_health += bandage[2];
                success_time = 0;
            }
            
            if (my_health > health) my_health = health;
        }
    }
    return my_health;
}