// PBLE 1 - 25102B0075_Rishikesh Dhamdhere
#include <stdio.h>

#define MAX 100

int n;
int id[MAX];
float profit[MAX], weight[MAX], ratio[MAX], capacity;
float fraction[MAX];
float totalValue = 0, totalWeight = 0;

//Function to take input from User
void enterDetails()
{
    int i;
    printf("Enter number of packages: ");
    fflush(stdout); // Flush the output buffer to ensure the prompt is displayed immediately
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nPackage %d\n", i + 1);
        printf("Enter profit: ");
        fflush(stdout);
        scanf("%f", &profit[i]);
        printf("Enter weight: ");
        fflush(stdout);
        scanf("%f", &weight[i]);
        id[i] = i + 1; // Assign package ID
    }

    printf("\nEnter vehicle carrying capacity : ");
    fflush(stdout);
    scanf("%f", &capacity);
}

//Function to print the profit and weight of each package
void printDetails()
{
    int i;
    printf("\nPackage Details:\n");
    printf("Package\tProfit\tWeight\tProfit/Weight\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, profit[i], weight[i], fraction[i]);
    }
}

//Function to compute profit to weight ratio and display it
void calculateRatio()
{
    int i;
    printf("\nProfit to Weight Ratio:\n");
    printf("Package\tProfit/Weight\tRatio(P/W)\n");
    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, profit[i], weight[i], ratio[i]);
    }
}

//Function to sort all packages in decreasing order of ratio using bubble sort & keeping profit[], weight[] and ratio[] in sync
void sortByRatio()
{
    int i,j,ti;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                ti = id[j];
                id[j] = id[j + 1];
                id[j + 1] = ti;
            }
        }
    }

    printf("\nPackages sorted in decreasing order of profit to weight ratio:\n");
    printf("Package\tProfit\tWeight\tProfit/Weight\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", id[i], profit[i], weight[i], ratio[i]);
    }
}

//Function to greedily fill the vehcile with whole pakcages while they fir, then takes only the fraction of next package needed to use up the remaining capacity. Stores the reuslt in totalValue/toalWeight.
void findMaxValue()
{
    int i;
    float remaining = capacity;

    totalValue = 0;
    totalWeight = 0;

    printf("\nPackage Added\tWeight\tRemaining Capacity\tProfit Earned\n");
    
    for (i = 0; i < n; i++)
    {
        if (remaining <=0)
        {
            fraction[i] = 0; // No more packages can be taken
            continue;
        }
        else if (weight[i] <= remaining)
        {
            fraction[i] = 1; 
            totalValue += profit[i]; // Update total value and weight
            totalWeight += weight[i]; // Update total value and weight
            remaining -= weight[i]; // Update remaining capacity
            fraction[i] = 1; // Whole package taken

            printf("%d\t\t%.2f\t%.2f\t\t\t%.2f\n",id[i], weight[i], remaining, totalValue);
        }
        else
        {
            fraction[i] = remaining / weight[i]; // Fraction of package taken
            totalValue += profit[i] * fraction[i]; // Update total value and weight
            totalWeight += weight[i] * fraction[i]; // Update total value and weight

            printf("%d\t\t%.2f\t%.2f\t\t\t%.2f (%.2f * %.2f)\n",id[i], weight[i], remaining, totalValue, profit[i]/weight[i], remaining);

            remaining = 0; // Vehicle is full
        }
    }

    printf("\nTotal Value in Vehicle: %.2f\n", totalValue);
    printf("Total Weight in Vehicle: %.2f\n", totalWeight);
}

//Function to display the fraction of each package taken in the vehicle along with the total value and weight of the packages in the vehicle.
void displaySelected()
{
    int i;
    printf("\nSelected Packages:\n");
    printf("Package\tProfit\tWeight\tFraction Taken\n");
    for (i = 0; i < n; i++)
    {
        if (fraction[i] > 0)
        {
            printf("%d\t%.2f\t%.2f\t%.2f\n", id[i], profit[i], weight[i], fraction[i]);
        }
    }
    printf("\nTotal Value in Vehicle: %.2f\n", totalValue);
    printf("Total Weight in Vehicle: %.2f\n", totalWeight);
}

//Main Function: Repeats the process of taking input, calculating ratios, sorting, finding max value, and displaying selected packages until the user chooses to exit.
int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Enter Package Details\n");
        printf("2. Print Package Details\n");
        printf("3. Calculate Profit/Weight of all objects\n");
        printf("4. Sort Packages by descending order of Profit/Weight\n");
        printf("5. Find Maximum Value in Vehicle\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        fflush(stdout);
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterDetails();
                break;
            case 2:
                printDetails();
                break;
            case 3:
                calculateRatio();
                break;
            case 4:
                sortByRatio();
                break;
            case 5:
                findMaxValue();
                break;
            case 6:
                displaySelected();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while (choice != 7);
    return 0;
}
