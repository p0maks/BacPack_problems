#include <iostream>

int max(int number1, int number2) {
    if (number1 > number2) {
        return number1;
    }
    else return number2;
}
int main()
{
    int count;
    int max_weight;
    std::cout << "Input max weight ";
    std::cin >> max_weight;
    std::cout << "Input max count ";
    std::cin >> count;
    int** list = new int* [count + 2];
    int* cost_list = new int[count + 1];
    int* weight_list = new int[count + 1];

}