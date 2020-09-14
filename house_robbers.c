int rob(int* nums, int numsSize)
{
    int even;
    int odd;
    int i;
    
    even = 0;
    odd = 0;
    i = 0;
    
    while (i < numsSize)
    {
        if (i % 2 == 0)
            even = (nums[i] + even) > odd ? (nums[i] + even) : odd;
        else
            odd = (nums[i] + odd) > even ? (nums[i] + odd) : even;
        i++;
    }
    return (even > odd ? even : odd);
}
