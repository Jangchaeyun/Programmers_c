#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 1000
#define MAX_ROOMS 1000

typedef struct {
	int start;
	int end;
} Booking;

int compare(const void* a, const void* b) {
	Booking* bookingA = (Booking*)a;
	Booking* bookingB = (Booking*)b;

	if (bookingA->start == bookingB->start) {
		return bookingA->end - bookingB->end;
	}
	return bookingA->start - bookingB->start;
}

int solution(const char*** book_time, size_t book_time_rows, size_t book_time_cols) {
	Booking bookings[MAX_BOOKINGS];
	int endTimes[MAX_ROOMS] = { 0 };
	int roomCount = 0;

	for (size_t i = 0; i < book_time_rows; i++) {
		int startHour = atoi(book_time[i][0]);
		int startMinute = atoi(&book_time[i][0][3]);
		int endHour = atoi(book_time[i][1]);
		int endMinute = atoi(&book_time[i][1][3]);

		int startTime = startHour * 60 + startMinute;
		int endTime = endHour * 60 + endMinute + 10;

		bookings[i].start = startTime;
		bookings[i].end = endTime;
	}

	qsort(bookings, book_time_rows, sizeof(Booking), compare);

	for (size_t i = 0; i < book_time_rows; i++) {
		int assigned = 0;
		for (int j = 0; j < roomCount; j++) {
			if (endTimes[j] <= bookings[i].start) {
				endTimes[j] = bookings[i].end;
				assigned = 1;
				break;
			}
		}
		
		if (!assigned) {
			endTimes[roomCount++] = bookings[i].end;
		}
	}
	return roomCount;
}