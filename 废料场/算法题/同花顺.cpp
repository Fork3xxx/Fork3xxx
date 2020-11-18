/**
 *  题目：从扑克牌中随机抽5张牌，
 * 判断是不是一个顺子
 * 即这5张牌是不是连续的
 * 2-10为数字本身，A为1，J为11，Q为12，K为13，
 * 而大小王可以看成任意数字。
 */

/**
 * 排序
 */
int cmp(const int* _a, const int* _b)
{
    int* a = (int*)_a;
    int* b = (int*)_b;
    return *a-*b; //递增排序
}

//判断同花顺
bool isStraight(int* nums, int numsSize)
{
    if (nums == nullptr || numsSize == 0)
        return false;
    int lack = 0;
    int zero_count = 0;
    int i,j;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < 5; i++)
    {
        if (nums[i] == 0)
        {
            zero_count++; //计算0(大王小王)的个数
        }else
        {
            j = i;
            break;
        }        
    }
    for (j = i + 1; j < numsSize; j++)
    {
        if ( nums[j] == nums[j-1])
        {    //除0之外还有相同元素则可直接判断不可能是顺子
            return false;
        }else
        {
            lack += abs(nums[j] - nums[j-1]-1); //顺子中缺的牌
        }   
    }
    if (lack <= zero_count)
    {//如果缺的少于0的个数，可以用0补全，即组成顺子
        return true;
    }
    else
    {
        return false;
    }  
}

