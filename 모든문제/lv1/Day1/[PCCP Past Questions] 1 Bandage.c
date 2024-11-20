#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int t = 0;               
    int count = -1;         
    int attack_count = 0;
    int hp = health;         
    int end_t = attacks[attacks_rows - 1][0];

    while (t <= end_t) {
        int attack_time = attacks[attack_count][0];

        if (attack_time == t) {
            int damage = attacks[attack_count][1];
            hp -= damage;

            if (hp <= 0) return -1;

            count = 0;      
            attack_count++;
        }
        else {
            hp = min(hp + bandage[1], health);
            count++;
            
            if (count == bandage[0]) {
                hp = min(hp + bandage[2], health);
                count = 0;
            }
        }

        t++; 
    }

    return hp;
}