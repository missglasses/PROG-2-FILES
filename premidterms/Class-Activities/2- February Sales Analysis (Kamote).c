#include <stdio.h>
#define FEB_DAYS 28
#define DAYS_IN_WEEK 7
#define WEEKS 4

float getMaxPrice(float prices[], int n);     // Returns the highest Camote price from the array
float getMinPrice(float prices[], int n);     // Returns the lowest Camote price from the array
float getAveragePrice(float prices[], int n); // Returns the average Camote price for the given range
void displayPrice(float prices[], int n);     // Displays all Camote prices in a clean, formatted output

/*Requirements
The program should handle 28 float values, representing daily prices for February.
It should calculate and display:
All daily prices.
Maximum and minimum prices for the month.
Weekly average prices (4 weeks).
Average price for the entire month. */

int main()
{
    float feb[FEB_DAYS] = {15.0, 12.0, 8.0, 10.0, 15.0, 12.0, 12.0,
                           12.0, 12.0, 8.0, 10.0, 15.0, 12.0, 10.0,
                           15.0, 13.0, 12.0, 12.0, 14.0, 15.0, 15.0,
                           15.0, 12.0, 8.0, 10.0, 15.0, 12.0, 12.0};

    printf("------------------------------------\n");
    displayPrice(feb, FEB_DAYS);

    printf("\n\n====MONTHLY STATS====\n\n");
    printf("Maximum price: Php %.2f\n", getMaxPrice(feb, FEB_DAYS));
    printf("Minimum price: Php %.2f\n", getMinPrice(feb, FEB_DAYS));

    printf("\n====WEEKLY AVERAGE PRICES====\n\n");
    for (int week = 0; week < WEEKS; week++)
    {
        int start = week * DAYS_IN_WEEK;
        printf("Week %d: Php %.2f\n", week + 1,
               getAveragePrice(feb + start, DAYS_IN_WEEK));
    }

    printf("\nAverage price for the entire month: Php %.2f\n\n", getAveragePrice(feb, FEB_DAYS));
    printf("------------------------------------\n");

    return 0;
}

float getMaxPrice(float prices[], int n)
{
    float max = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > max)
        {
            max = prices[i];
        }
    }
    return max;
}

float getMinPrice(float prices[], int n)
{
    float min = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
    }
    return min;
}

float getAveragePrice(float prices[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += prices[i];
    }
    return sum / n;
}

void displayPrice(float prices[], int n)
{
    printf("\n==== FEBRUARY DAILY PRICES ====\n");

    for (int week = 0; week < WEEKS; week++)
    {
        printf("\n|| Week %d ||\n", week + 1);

        for (int day = 0; day < DAYS_IN_WEEK; day++)
        {
            int day_index = (week * DAYS_IN_WEEK) + day;
            printf("Day %2d: Php %6.2f\n", day_index + 1, prices[day_index]);
        }
    }
}

// void displayPrice(float prices[], int n)
// {
//     printf("\n\n====FEBRUARY DAILY PRICES====\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("Day %2d: Php %.2f\n", i + 1, prices[i]);
//     }
// }
