#include <stdio.h>

int main(void)
{
    int testCase;
    scanf("%d", &testCase);

    while (testCase--) {
        int n;
        scanf("%d", &n);

        long long minimum = 0;
        long long maximum = 0;
        long long value = 0;
        long double average = 0.0L;
        long double squaredDifferenceSum = 0.0L;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &value);
            if (i == 0 || value < minimum) minimum = value;
            if (i == 0 || value > maximum) maximum = value;

            long double difference = value - average;
            average += difference / (i + 1);
            squaredDifferenceSum += difference * (value - average);
        }

        long double variance = squaredDifferenceSum / n;
        printf("%lld %.3f\n", maximum - minimum, (double)variance);
    }

    return 0;
}
