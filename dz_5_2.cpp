#include <iostream>
#include <string>

int main(int argc, char * argv [])
{
    #define ELEMENTS_COUNT 10
    
    int array[ELEMENTS_COUNT]; // Для случайности не инициализируем массив сразу, а оставляем неопределённые значения
    int minimum = ((int)-1) & ~((int)1 << ((sizeof(int) <<  3) - 1)); // Инициализируем максимальным возможным значением знакового типа данных "int"
    int maximum = ((int)1 << ((sizeof(int) <<  3) - 1)); // Инициализируем минимальным возможным значением знакового типа данных "int"

    for(int index = 0; index < ELEMENTS_COUNT; index++)
    {
        // Перемешиваем эти неопределённые значения (инициализируем массив)
        array[index] = ( ((array[index] ^ array[ELEMENTS_COUNT - index - 1]) + (array[0]/3))  %  789 ) & 0x00000FFF;

        if(array[index] < minimum) minimum = array[index];
        if(array[index] > maximum) maximum = array[index];
        
        std::cout << array[index] << ((index < (ELEMENTS_COUNT - 1)) ? ", " : " \n");
    }

    std::cout << "minimum = " << minimum << "\n";
    std::cout << "maximum = " << maximum << "\n";
    
    return 0;
}
