#include <iostream>

int main(int argc, char * argv [])
{
    std::cout << "Input array  : ";

    #define ELEMENTS_COUNT 10
    int array[ELEMENTS_COUNT]; // Для генерации значений похожих на случайные, не инициализируем массив сразу, а сначала оставляем неопределённые значения
    for(int cur_index = 0; cur_index < ELEMENTS_COUNT; cur_index++) 
    {
        // Затем перемешиваем эти неопределённые значения, тем самым инициализируем массив значениями, которые ещё больше похожи на случайные
        array[cur_index] = ( ((array[cur_index] ^ array[ELEMENTS_COUNT - cur_index - 1]) + (array[0] / 3))  %  789 ) & 0x00000FFF;
        std::cout << array[cur_index] << " ";
    }

    std::cout << std::endl << "Output array : ";
    for(int pass_stop_index = 0; pass_stop_index < ELEMENTS_COUNT; pass_stop_index++)
    {
        for(int cur_index = (ELEMENTS_COUNT - 1), prev_index = (ELEMENTS_COUNT - 2); cur_index > pass_stop_index; cur_index--, prev_index--)
        {
            if(array[cur_index] < array[prev_index])
            {
                array[cur_index]  ^= array[prev_index];
                array[prev_index] ^= array[cur_index];
                array[cur_index]  ^= array[prev_index];
            }
        }
        std::cout << array[pass_stop_index] << " ";
    }
    std::cout << std::endl;

    return 0;
}