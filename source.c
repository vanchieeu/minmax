#include <stdio.h>

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(long *a, int l, int r) {
    long p = a[(l+r)/2];

    int i = l, j = r;
    while (i < j) {
        while (a[i] < p)
            i++;

        while (a[j] > p)
            j--;
        
        if (i <= j) {
            swap(a+i, a+j);

            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(a, i, r);
    if (l < j)
        quickSort(a, l, j);
} 

int main() {
    int n;
    scanf("%d", &n);

    long a[n];
    long b[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
        b[i] = a[i];
    }

    quickSort(b, 0, n-1);
    for (int i = 0; i < n; i++)
        if (a[i] == b[0]) {
            printf("%ld %d ", a[i], i+1);
            break;
        }

    for (int i = 0; i < n; i++)
        if (a[i] == b[n-1]) {
            printf("%ld %d", a[i], i+1);
            break;
        }
    return 0;
}