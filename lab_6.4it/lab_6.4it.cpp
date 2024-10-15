#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(int* a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() * (High - Low) / RAND_MAX;
}

void Print(int* a, const int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

int CountInRange(int* a, const int n, const int A, const int B) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= A && a[i] <= B)
            count++;
    }
    return count;
}

double SumAfterMax(int* a, const int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }

    double sum = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

void SortEvenDescending(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] % 2 == 0 && abs(a[j]) > abs(a[i])) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << " n = ";
    cin >> n;

    int A, B;
    cout << " A = ";
    cin >> A;
    cout << " B = ";
    cin >> B;

    auto* a = new int[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    int count = CountInRange(a, n, A, B);
    cout << " [A, B]: " << count << endl;

    int sum = SumAfterMax(a, n);
    cout << "Sum after max element: " << sum << endl;

    SortEvenDescending(a, n);
    cout << "Array after sorting even elements: ";
    Print(a, n);

    delete[] a;
    return 0;
}