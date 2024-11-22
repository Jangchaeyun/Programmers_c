#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void split(const char* input, char delimiter, char result[][12], int* count) {
    char buffer[50];
    strcpy(buffer, input);
    char* token = strtok(buffer, &delimiter);
    *count = 0;

    while (token != NULL) {
        strcpy(result[*count], token);
        (*count)++;
        token = strtok(NULL, &delimiter);
    }
}

void parse_terms(const char* terms[], size_t terms_len, char types[][12], int dates[], int* term_count) {
    for (size_t i = 0; i < terms_len; i++) {
        char buffer[50];
        strcpy(buffer, terms[i]);

        char* type = strtok(buffer, " ");
        char* date = strtok(NULL, " ");

        strcpy(types[*term_count], type);
        dates[*term_count] = atoi(date);
        (*term_count)++;
    }
}

int find_term_date(const char* type, char types[][12], int dates[], int term_count) {
    for (int i = 0; i < term_count; i++) {
        if (strcmp(type, types[i]) == 0) {
            return dates[i];
        }
    }
    return 0;
}

void calculate_expiry_date(int* year, int* month, int* day, int additional_months) {
    *month += additional_months;

    while (*month > 12) {
        *month -= 12;
        (*year)++;
    }

    (*day)--;

    if (*day == 0) {
        (*month)--;
        *day = 28;
        if (*month == 0) {
            *month = 12;
            (*year)--;
        }
    }
}

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len, int* return_size) {
    char today_parts[3][12];
    int today_count = 0;

    split(today, '.', today_parts, &today_count);
    int ty = atoi(today_parts[0]);
    int tm = atoi(today_parts[1]);
    int td = atoi(today_parts[2]);

    char types[26][12];
    int dates[26];
    int term_count = 0;

    parse_terms(terms, terms_len, types, dates, &term_count);

    int* result = (int*)malloc(privacies_len * sizeof(int));
    int result_count = 0;

    for (size_t i = 0; i < privacies_len; i++) {
        char buffer[50];
        strcpy(buffer, privacies[i]);

        char* date = strtok(buffer, " ");
        char* type = strtok(NULL, " ");

        char date_parts[3][12];
        int date_count = 0;

        split(date, '.', date_parts, &date_count);
        int dy = atoi(date_parts[0]);
        int dm = atoi(date_parts[1]);
        int dd = atoi(date_parts[2]);

        int additional_months = find_term_date(type, types, dates, term_count);
        calculate_expiry_date(&dy, &dm, &dd, additional_months);

        if (ty > dy || (ty == dy && tm > dm) || (ty == dy && tm == dm && td > dd)) {
            result[result_count++] = i + 1;
        }
    }

    *return_size = result_count;
    return result;
}