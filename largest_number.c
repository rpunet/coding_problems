  
static int	ft_dec_count(unsigned int ncpy, int lng)
{
	while (ncpy >= 10)
	{
		ncpy /= 10;
		lng++;
	}
	return (lng);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*itoa;
	int				sign;

	sign = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	len = ft_dec_count(nbr, 1);
	len += sign;
	if (!(itoa = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	itoa[len] = '\0';
	while (len-- > sign)
	{
		itoa[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		itoa[0] = '-';
	return (itoa);
}

int     ft_pow(int a, int exp)
{
    int ret;
    
    ret = 1;
    while (exp-- > 0)
        ret *= a;
    return (ret);
}

int     ft_first_digit(int num)
{
    int temp;
    int count;
    int first_dig;
    
    temp = num;
    count = 1;
    while (temp >= 10)
    {
        temp /= 10;
        count++;
    }
    first_dig = num / ft_pow(10, (count - 1));
    return (first_dig);
}
    
void    ft_swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_sort(int *nums, int size)
{
    int i;
    int j;
    int temp;
    int first_dig;
    
    i = 0;
    j = 0;
    while (i < size)
    {
        while (j < size)
        {
            if (ft_first_digit(nums[j]) > ft_first_digit(nums[i]))
                ft_swap(&nums[j], &nums[i]);
            j++;
        }
        i++;
    }
}

char *largestNumber(int* nums, int numsSize)
{
    int     i;
    int     temp;
    int     count;
    char    *ret;
    int     index;
    
    ft_sort(nums, numsSize);
    i = 0;
    count = 1;
    while (i < numsSize)
    {
        temp = nums[i];
        while (temp >= 10)
        {
            temp /= 10;
            count++;
        }
        i++;
        count++;
    }
    ret = malloc(count * sizeof(char));
    i = 0;
    index = 0;
    while (i < numsSize)
    {
        temp = nums[i];
        count = 1;
        while (temp >= 10)
        {
            temp /= 10;
            count++;
        }
        ret[index] = ft_itoa(nums[i]);
        index += count;
    }
    ret[index] = '\0';
    return (ret);
}
