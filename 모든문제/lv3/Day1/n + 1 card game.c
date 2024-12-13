#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 1000

bool MatchCards(int* cards1, int* size1, int* cards2, int* size2, int target) {
    for (int i = 0; i < *size1; i++) {
        for (int j = 0; j < *size2; j++) {
            if (cards1[i] + cards2[j] == target) {
                for (int k = i; k < *size1 - 1; k++) {
                    cards1[k] = cards1[k + 1];
                }
                (*size1)--;

                for (int k = j; k < *size2 - 1; k++) {
                    cards2[k] = cards2[k + 1];
                }
                (*size2)--;

                return true;
            }
        }
    }
    return false;
}

int solution(int coin, int cards[], size_t cards_len) {
    int hands[MAX_CARDS], draws[MAX_CARDS];
    int hands_size = 0, draws_size = 0;
    int answer = 1;
    int target = cards_len + 1;

    for (size_t i = 0; i < cards_len / 3; i++) {
        hands[hands_size++] = cards[i];
    }

    for (size_t i = cards_len / 3; i < cards_len; i += 2) {
        draws[draws_size++] = cards[i];
        draws[draws_size++] = cards[i + 1];

        if (MatchCards(hands, &hands_size, hands, &hands_size, target)) {
            
        }
        else if (coin >= 1 && MatchCards(hands, &hands_size, draws, &draws_size, target)) {
            coin -= 1;
        }
        else if (coin >= 2 && MatchCards(draws, &draws_size, draws, &draws_size, target)) {
            coin -= 2;
        }
        else {
            break;
        }

        answer++;
    }

    return answer;
}
