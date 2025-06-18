#include <stdio.h>
#define FEB_DAYS 28
#define DAYS 7
#define NUM_OF_WEEKS (FEB_DAYS / DAYS)

void rankPrices(float feb[]); // top price per week
void getMinMax(float arr[], int range, float *min, float *max, float *ave);
void printPrice(float arr[], int x);
void rankWeeks(float averages[], int weeks[]); // top

int main()
{
    float feb[FEB_DAYS] = {15.0, 12.0, 8.0, 10.0, 15.0, 12.0, 12.0,
                           12.0, 12.0, 8.0, 10.0, 15.0, 12.0, 10.0,
                           15.0, 13.0, 12.0, 12.0, 14.0, 15.0, 15.0,
                           15.0, 12.0, 8.0, 10.0, 15.0, 12.0, 12.0};

    rankPrices(feb);
    return 0;
}

void rankPrices(float feb[])
{
    printf("\n\n|| FEBRUARY PRICES ||\n\n ");

    float weekAves[NUM_OF_WEEKS];
    int traceWeek[NUM_OF_WEEKS];
    float max = feb[0], min = feb[0];

    for (int week = 0; week < NUM_OF_WEEKS; week++)
    {
        int x = week * DAYS;
        printf("\n===== Week %d =====\n", week + 1);

        float weekMin, weekMax, weekAve;
        getMinMax(feb, x, &weekMin, &weekMax, &weekAve);

        // comparison
        if (weekMax > max)
            max = weekMax;
        if (weekMin < min)
            min = weekMin;

        // this will store weekly average for ranking
        weekAves[week] = weekAve;
        traceWeek[week] = week;

        for (int i = 0; i < DAYS; i++)
        {
            int day = x + i;
            printf("Day %2d: Php ", day + 1);
            printPrice(feb, day);
            printf("\n");
        }

        printf("Weekly Min: Php %.2f | Max: Php %.2f | Ave: Php %.2f\n",
               weekMin, weekMax, weekAve);
    }

    // rank the weeks by average
    rankWeeks(weekAves, traceWeek);
    printf("\n==== Weekly Average====\n");
    for (int i = 0; i < NUM_OF_WEEKS; i++)
    {
        printf("Rank #%d: Week %d (Ave: Php %.2f)\n",
               i + 1, traceWeek[i] + 1, weekAves[traceWeek[i]]);
    }

    printf("\n==== Highest & Lowest Price ====\n");
    printf("Minimum: Php %.2f\n", min);
    printf("Maximum: Php %.2f", max);
}

void getMinMax(float arr[], int range, float *min, float *max, float *ave)
{
    *min = arr[range];
    *max = arr[range];
    float sum = arr[range];

    for (int i = 1; i < DAYS; i++)
    {
        if (arr[range + i] < *min)
            *min = arr[range + i];
        if (arr[range + i] > *max)
            *max = arr[range + i];
        sum += arr[range + i];
    }
    *ave = sum / DAYS;
}

void rankWeeks(float averages[], int weeks[])
{
    for (int i = 0; i < NUM_OF_WEEKS - 1; i++)
    {
        for (int j = 0; j < NUM_OF_WEEKS - i - 1; j++)
        {
            if (averages[weeks[j]] < averages[weeks[j + 1]])
            {
                int temp = weeks[j];
                weeks[j] = weeks[j + 1];
                weeks[j + 1] = temp;
            }
        }
    }
}

void printPrice(float arr[], int x)
{
    printf("%.2f", arr[x]);
}
