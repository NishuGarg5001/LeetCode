#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
    int value;
    int used;
} Entry;

unsigned int hash(int key)
{
    return (unsigned) key * 2654435761u;
}

void map_put(Entry *table, int cap, int key, int value) 
{
    unsigned idx = hash(key) % cap;

    while (table[idx].used) 
        idx = (idx + 1) % cap;

    table[idx].key = key;
    table[idx].value = value;
    table[idx].used = 1;
}

int map_get(Entry *table, int cap, int key, int *out) {
    unsigned idx = hash(key) % cap;

    while (table[idx].used) 
    {
        if (table[idx].key == key) 
        {
            *out = table[idx].value;
            return 1;
        }
        idx = (idx + 1) % cap;
    }

    return 0;
}

int* twoSum(int *nums, int numsSize, int target, int *returnSize) 
    {
        int cap = numsSize * 2;
        Entry *table = calloc(cap, sizeof *table);
        if (!table) 
            return NULL;

        for(int i = 0; i < numsSize; i++)
        {
            int index;
            if(map_get(table, cap, target - nums[i], &index))
            {
                int *result = malloc(2 * sizeof *result);
                if(!result)
                {
                    free(table);
                    return NULL;
                }
                result[0] = index;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            map_put(table, cap, nums[i], i);
        }
        free(table);
        *returnSize = 0;
        return NULL;
    }

int main()
{
    int returnSize;
    int *result;
    int nums1[] = {3, 6, 7, 0};
    int nums2[] = {1, 3, 4, 10};
    int nums3[] = {0, 1, 2};
    int nums4[] = {-100, 50, 7, 11};
    int nums5[] = {33, 6, -2, 19, 40, 99};
    int *test_cases[5] = {nums1, nums2, nums3, nums4, nums5};
    int lens[5] = {4, 4, 3, 4, 6};
    int target[5] = {7, 5, 1, -50, 97};

    for (int i = 0; i < 5; i++)
    {
        result = twoSum(test_cases[i], lens[i], target[i], &returnSize);
        printf("Size of the returned array: %d\n", returnSize);
        if(result == NULL)
            printf("No solution exists!\n");
        else
            printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    }
    printf("Press any key to exit...");
    getchar();
    return 0;
}