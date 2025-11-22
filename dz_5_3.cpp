#include <iostream>

int main(int argc, char * argv [])
{
    #define I_COUNT 3
    #define J_COUNT 6

    int array[I_COUNT][J_COUNT]; // Для генерации значений похожих на случайные, не инициализируем массив сразу, а сначала оставляем неопределённые значения

    int index_of_minimum[2] = {0, 0};
    int index_of_maximum[2] = {0, 0};

    for(int i = 0; i < I_COUNT; i++)
    {wq
        for(int j = 0; j < J_COUNT; j++)
        {
            // Затем перемешиваем эти неопределённые значения, тем самым инициализируем массив значениями, которые ещё больше похожи на случайные
            array[i][j] = ( ( ((array[i][j]/3) ^ (array[I_COUNT - i - 1][j]/5) ^ (array[i][J_COUNT - j - 1]/7) ^ (array[I_COUNT - i - 1][J_COUNT - j - 1]/9)))  %  789 ) & 0x00000FFF;

            if(array[i][j] < array[index_of_minimum[0]][index_of_minimum[1]]) 
            {
                index_of_minimum[0] = i;
                index_of_minimum[1] = j;
            }
            
            if(array[i][j] > array[index_of_maximum[0]] [index_of_maximum[1]]) 
            {
                index_of_maximum[0] = i;
                index_of_maximum[1] = j;
            }
            
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Index of minimum = " << index_of_minimum[0] << " " << index_of_minimum[1] << "\n";
    std::cout << "Index of maximum = " << index_of_maximum[0] << " " << index_of_maximum[1] << "\n";
    
    return 0;
}
