#include <iostream>
#include <string>

int main(int argc, char * argv [])
{
    #define ELEMENTS_COUNT 10

    int array[ELEMENTS_COUNT]; // Для случайности не инициализируем массив сразу, а оставляем неопределённые значения
    for(int index = 0; index < ELEMENTS_COUNT; index++)
    {
        // Перемешиваем эти неопределённые значения (инициализируем массив)
        array[index] = ( ((array[index] ^ array[ELEMENTS_COUNT - index - 1]) + (array[0]/3))  %  789 ) & 0x00000FFF;
        
        std::cout << array[index] << ((index < (ELEMENTS_COUNT - 1)) ? ", " : " \n");
    }
    
    return 0;
}
