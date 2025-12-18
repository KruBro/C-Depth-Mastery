/**
 * Project: Statistical Number Cruncher
 * Description: Calculates Mean, Median, Mode, and Standard Deviation.
 * Concepts: Bubble Sort, Math Library, O(N) Frequency Analysis.
 * Note: Requires linking with -lm (math library) on some compilers.
 */

#include <stdio.h>
#include <math.h>

// --- Function Prototypes ---
void scanArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void swap(int *a, int *b);

float findMean(int arr[], int size);
float findMedian(int arr[], int size);
int findMode(int arr[], int size);
float findStandardDeviation(int arr[], int size, float mean);

int main()
{
    int size;

    printf("--- Statistical Number Cruncher ---\n");
    printf("Enter the number of elements (N): ");
    if (scanf("%d", &size) != 1 || size <= 0) 
    {
        printf("Invalid input size.\n");
        return 1;
    }

    // VLA (Variable Length Array)
    int arr[size];

    // 1. Input
    scanArray(arr, size);

    // 2. Sort (Critical Step: Median and Mode depend on this)
    bubbleSort(arr, size);
    
    printf("\n--- Results ---\n");
    printf("Dataset (Sorted): \t");
    printArray(arr, size);

    // 3. Statistics
    float mean = findMean(arr, size);
    printf("MEAN:   \t%g\n", mean);

    float median = findMedian(arr, size);
    printf("MEDIAN: \t%g\n", median);

    int mode = findMode(arr, size);
    printf("MODE:   \t%d\n", mode);

    float sd = findStandardDeviation(arr, size, mean);
    printf("SD:     \t%g\n", sd);

    return 0;
}

// --- Implementations ---

void scanArray(int arr[], int size)
{
    printf("Enter %d numbers:\n", size);
    for(int i = 0; i < size; i++)
    {
        printf("[%d]--> ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

/**
 * Sorts array in Ascending Order using Bubble Sort.
 * Complexity: O(N^2)
 */
void bubbleSort(int arr[], int size)
{
    int swapped;

    for(int i = 0; i < size - 1; i++)
    {
        swapped = 0;
        // Optimization: 'size - i - 1' prevents checking already sorted tail
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        // If no swaps occurred, array is already sorted
        if(swapped == 0) break;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

float findMean(int arr[], int size)
{
    long long sum = 0; // Prevent overflow for large integers
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / (float)size;
}

float findMedian(int arr[], int size) 
{
    // If odd size: Return the exact middle element
    if (size % 2 != 0)
    {
        return arr[size / 2];
    } 
    // If even size: Return average of the two middle elements
    else 
    {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

/**
 * Finds the most frequent number.
 * Note: Relies on the array being SORTED.
 * Complexity: O(N) single pass.
 */
int findMode(int arr[], int size)
{
    int mode = arr[0];
    int currentCount = 1;
    int maxCount = 1;

    for(int i = 1; i < size; i++)
    {
        if(arr[i] == arr[i - 1])    
            currentCount++;
        else    
            currentCount = 1; // Reset count for new number

        if(currentCount > maxCount)
        {
            maxCount = currentCount;
            mode = arr[i];
        }
    }
    return mode;
}

float findStandardDeviation(int arr[], int size, float mean)
{
    float sumSqDiff = 0.0;
    for(int i = 0; i < size; i++)
    {
        float diff = arr[i] - mean;
        sumSqDiff += pow(diff, 2);
    }
    return sqrtf(sumSqDiff / size);
}