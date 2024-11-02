#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int abs(int n) {
    if (n < 0) return -n;
    return n;
}
int solution(int a, int b, int c, int d) {
    if (a == b) {
        if (b == c) {
            if (c == d) return 1111 * a;
            return (10 * a + d) * (10 * a + d);
        }
        if (b == d) return (10 * a + c) * (10 * a + c);
        if (c == d) return (a + c) * abs(a - c);
        return c * d; 
    }
    if (b == c) {
        if (c == d) return (10 * b + a) * (10 * b + a);
        if (a == d) return (a + b) * abs(a - b);
        return a * d;
    }
    if (c == d) {
        if (a == c) return (10 * a + b) * (10 * a + b);
        return a * b;
    }
    if (a == c) {
        if (b == d) return (a + b) * abs(a - b);
        return b * d; 
    }
    if (a == d) return b * c;
    if (b == d) return a * c;
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}