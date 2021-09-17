// HomeWork5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


void printArray(double array [], int arraySize) // Функция для задания 1
{
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << "  | ";
    }
    std::cout << std::endl;
}
void printArray(int array[], int arraySize) // Функция для задания 2
{
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << "  | ";
    }
    std::cout << std::endl;
}

void initializeArray(double* arrayPtr, int arraySize) // Функция для задания 1
{
    for (int i = 0; i < arraySize; i++) {
        arrayPtr[i] = ( rand() % 10 ) + ( 0.333 * ( rand() % 10)) + (0.25 * (rand() % 10));
    }
}
void initializeArray(int* arrayPtr, int arraySize) // Функция для задания 2
{
    for (int i = 0; i < arraySize; i++) {
        arrayPtr[i] = rand() % 2;
    }
}

void replacer(int* arrayPtr, int arraySize) // Функция для задания 2
{
    for (int i = 0; i < arraySize; i++) {
        arrayPtr[i] = arrayPtr[i] = 0 ? 1 : 0;
    }
}

void initializeArrayThree (int* arrayPtr, int arraySize) // Функция для задания 3
{
    for (int i = 0; i < arraySize; i++)
    {
        arrayPtr[i] = i * 3 + 1;
    }
}

void shiftArray(double* arrayPtr, const int arraySize, int shiftSize) // Функция для задания 4
{ 
    shiftSize = abs(shiftSize) < arraySize ? shiftSize : shiftSize % arraySize;
    shiftSize = shiftSize >= 0 ? shiftSize : arraySize - shiftSize;
    for (int i = 0; i < shiftSize; i++)
    {
        double buffer = arrayPtr[0];
        for (int i = 0; i < arraySize - 1; i++)
        {
            arrayPtr[i] = arrayPtr[i+1];
        }
        arrayPtr[arraySize - 1] = buffer;
    }
}

bool balance(int array[], int arraySize) // Функция для задания 5
{
    int sumRight{ 0 };
    int sumLeft = { 0 };
    for (int i = 0; i < arraySize; i++)
    {
        sumRight = sumRight + array[i];
    }
    for (int i = 0; i < arraySize; i++)
    {
        sumRight = sumRight - array[i];
        sumLeft = sumLeft + array[i];
        
        if (sumRight == sumLeft)
        {
            return true;
        }
        
    }
    return false;
}

int main()
{
    const int size = 10;
    std::cout << "Task 1" << std::endl;
    double taskOneArray[size] {0};
    initializeArray( taskOneArray, size);
    printArray(taskOneArray, size);
    
    std::cout << std::endl << "Task 2" << std::endl;
    int taskTwoArray[size]{ 0 };
    initializeArray(taskTwoArray, size);
    std::cout << "Intitial array: ";
    printArray(taskTwoArray, size);
    replacer(taskTwoArray, size);
    std::cout << "Replaced array: ";
    printArray(taskTwoArray, size);

    std::cout << std::endl << "Task 3" << std::endl;
    const int sizeTaskThree = 8;
    int taskThreeArray[sizeTaskThree]{ 0 };
    initializeArrayThree(taskThreeArray, sizeTaskThree);
    printArray(taskThreeArray, sizeTaskThree);

    std::cout << std::endl << "Task 4" << std::endl;
    const int n = -3;
    double taskFourArray[size]{ 0 };
    initializeArray(taskFourArray, size);
    std::cout << "Intitial array: ";
    printArray(taskFourArray, size);
    shiftArray(taskFourArray, size, n);
    std::cout << " Shifted array: ";
    printArray(taskFourArray, size);

    std::cout << std::endl << "Task 5" << std::endl;
    int taskFiveArray[size];
    initializeArray(taskFiveArray, size);
    std::cout << "Intitial array: ";
    printArray(taskFiveArray, size);
    if (balance(taskFiveArray, size))
    {
        std::cout << "True" << std::endl;
    }
    else 
    {
        std::cout << "False" << std::endl;
    }
    std::cout << "Hello World!\n";
}

