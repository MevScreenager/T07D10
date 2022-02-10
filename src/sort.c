#include<stdio.h>
#include <stdlib.h>

int inputN(int *n);
int inputArry(int *a, int *n);
void output(int *a, int *n);
void quick_sort(int *a, int first, int last);

int main() {
    int n, *data;
    if (inputN(&n)) {
        data = (int *) malloc(n * sizeof(int));
        if (inputArry(data, &n)) {
            quick_sort(data, 0, n - 1);
            output(data, &n);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int inputN(int *n) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;
    if (*n <= 0) return 0;
    if (getchar() != 10) return 0;
    return 1;
}

int inputArry(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (p - a < *n - 1 && getchar() == 10) return 0;
    }
    if (getchar() != 10) return 0;
    return 1;
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right) {
                int time = a[left]; a[left] = a[right]; a[right] = time;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (p - a == *n - 1) {
            printf("%d", *p);
            free(a);
            return;
        }
        printf("%d ", *p);
    }
}
