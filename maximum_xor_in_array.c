/*int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int findMaximumXOR(int* nums, int numsSize)
{
    int i;
    int j;
    int max;
    
    i = 0;
    j = 0;
    max = 0;
    while (i < numsSize - 1)
    {
        j = i + 1;
        while (j < numsSize)
        {
            max = ft_max(max, nums[i] ^ nums[j]);
            j++;
        }
        i++;
    }
    return (max);
}*/
