#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* create_heap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void free_heap(MaxHeap* heap) {
    free(heap->data);
    free(heap);
}

void push(MaxHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        return;
    }
    heap->data[heap->size++] = value;
    int current = heap->size - 1;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap->data[parent] >= heap->data[current]) {
            break;
        }
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[current];
        heap->data[current] = temp;
        current = parent;
    }
}

int pop(MaxHeap* heap) {
    if (heap->size <= 0) {
        return 0;
    }
    int max_value = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int current = 0;
    while (true) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;

        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }
        if (largest == current) {
            break;
        }

        int temp = heap->data[current];
        heap->data[current] = heap->data[largest];
        heap->data[largest] = temp;
        current = largest;
    }
    return max_value;
}

int top(MaxHeap* heap) {
    if (heap->size <= 0) {
        return 0;
    }
    return heap->data[0];
}

int solution(int n, int k, int enemy[], size_t enemy_len) {
    int answer = 0;
    MaxHeap* heap = create_heap(enemy_len);

    for (int i = 0; i < enemy_len; i++) {
        if (n >= enemy[i]) {
            n -= enemy[i];
            push(heap, enemy[i]);
        }
        else {
            if (k == 0) {
                break;
            }
            if (heap->size > 0 && top(heap) > enemy[i]) {
                n += pop(heap);
                n -= enemy[i];
                push(heap, enemy[i]);
            }
            k--;
        }
        answer++;
    }

    free_heap(heap);
    return answer;
}