#include <iostream>
#include "string.h"
using std::cout;
using std::endl;
template <typename T>
void bubble_sort(T *array, int scale)
{
    T temp;
    for (int i = scale - 2; i != -1; i--)
    {
        int jend = i + 1;
        for (int j = 0; j != jend; j++)
        {
            if (array[j] > array[i + 1])
            {
                temp = array[j];
                array[j] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
template <typename T>
void select_sort(T *array, int scale)
{
    int i_end = scale - 1;
    T temp;
    int record = 0;
    for (int i = 0; i != i_end; i++)
    {
        record = i;
        for (int j = i; j != scale; j++)
        {
            if (array[j] < array[record])
            {
                record = j;
            }
        }
        temp = array[record];
        array[record] = array[i];
        array[i] = temp;
    }
}
template <typename T>
void insert_sort(T *array, int scale)
{
    T temp;
    for (int i = 1; i != scale; i++)
    {
        temp = array[i];
        for (int j = i - 1; j != -1; j--)
        {
            if (temp >= array[j])
            {
                array[j + 1] = temp;
                break;
            }
            else
            {
                array[j + 1] = array[j];
                array[j] = temp; //比较耗时长,比较有一个读a和b值得过程，然后比较要建立一个新的区间存储比较结果，而复制只是读取b的值，然后存储到a的位置，根本不需要读取a原来的值。
                continue;        //if(j = 0){array(1) = array[0]; array[0] = temp}
            }                    //其实也不一定，比如非基本数据结构赋值可能就慢得多。
        }
    }
}
template <typename T>
void shell_sort(T *array, int scale)
{
    for (int i = (scale) / 2; i != 0; i /= 2)
    {
        for (int j = 0; j != i; j++)
        {
            T temp;
            for (int k = 1; ((k + 1) * i + j) < scale + 1; k++)
            {
                temp = array[j + k * i];
                for (int l = k - 1; l != -1; l--)
                {
                    if (temp >= array[j + l * i])
                    {
                        array[j + (l + 1) * i] = temp;
                        break;
                    }
                    else
                    {
                        array[j + (l + 1) * i] = array[j + (l)*i];
                        array[j + l * i] = temp;
                        continue;
                    }
                }
            }
        }
    }
}
/*template <typename T>
T* merge_sort(T* array, int scale)
{
    if (scale == 1)
        return nullptr;
    else if (scale == 2)
    {
        if (array[0] > array[1])
        {
            int temp;
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return nullptr;
        }
        return nullptr;
    }
    else
    {
        T* arrays = array;
        int subscale1 = scale / 2;
        int subscale2 = scale - subscale1;
        T* container = new T[scale];
        T* second = array + subscale1;
        merge_sort<T>(array, subscale1);
        merge_sort<T>(second, subscale2);
        T* end1 = array + subscale1 - 1;
        T* end2 = second + subscale2 - 1;
        int record = 0;
        while (record != scale)
        {
            if (array == nullptr || second == nullptr)
            {
                for (; (!(array == nullptr)) ? array != end1 + 1 : second != end2 + 1; (!(array == nullptr)) ? array++ : second++)
                {
                    container[record] = (!(array == nullptr)) ? *array : *second;
                    record++;
                    continue;
                }
            }else
            if (*array > *second)
            {

                container[record] = *second;
                if ((int)end2 > (int)second) second++;
                else 
                {
                    second = nullptr;
                }
                record++;
            }
            else if (*array == *second)
            {
                container[record] = *array;
                if ((int)end1 > (int)array) array++;
                else
                {
                    array = nullptr;
                }
                record++;
            }
            else
            {
                container[record] = *array;
                if ((int)end1 > (int)array) array++;
                else
                {
                    array = nullptr;
                }
                record++;

            }
        }
        return container;
    }
}*/
template <typename T>
void merge_sort(T *array, int scale)
{
    if (scale == 1)
        return;
    else if (scale == 2)
    {
        if (array[0] > array[1])
        {
            T temp = array[0];
            array[1] = array[0];
            array[0] = temp;
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        int middle = scale / 2;
        T *second = array + middle;
        merge_sort<T>(array, middle);
        merge_sort<T>(second, scale - middle);
        T *container = new T[scale];
        while (array != second || second != array + scale)
        {
            if (*array > *second)
            {
                *container = *second;
                container++;
                second++;
            }
            else
            {
                *container = *array;
                container++;
                second++;
            }
        }
        for (T *i = (array == second) ? second : array; i != (array == second) ? array + scale : second; i++)
        {
            *container = *i;
        }
        delete[] container;
    }
}
int main()
{
    int scale = 10;
    int ok[] = {9, 18, 75, 6, 58, 4, 73, 2, 81, 0};
    shell_sort<int>(ok, scale);
    for (int i = 0; i != scale; i++)
    {
        cout << ok[i] << " ";
    }
}