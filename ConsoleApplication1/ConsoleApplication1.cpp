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
    for (int i = 0; i < count + 2; i++) list[i] = new int[max_weight + 2];
    for (int i = 0; i < count + 2; i++)
    {
        for (int j = 0; j < max_weight + 2; j++)
        {
            list[i][j] = 0;
        }
    }
    for (int i = 2; i < max_weight + 2; i++)
    {
        list[0][i] = i - 1;
    }
    for (int i = 2; i < count + 2; i++)
    {
        int x;
        std::cout << "Input " << i - 1 << " weight ";
        std::cin >> x;
        weight_list[i] = x;
        list[i][0] = i - 1;
        std::cout << "Input " << i - 1 << " cost ";
        std::cin >> x;
        cost_list[i] = x;
    }
    for (int i = 2; i < count + 2; i++)
    {
        for (int j = 2; j < max_weight + 2; j++)
        {
            if (j - 1 < weight_list[i])
            {
                list[i][j] = list[i - 1][j];
            }
            else if (j - 1 >= weight_list[i])
            {
                list[i][j] = max(list[i - 1][j], list[i - 1][j - weight_list[i]] + cost_list[i]);
            }
        }

    }
    for (int i = 0; i < count + 2; i++)
    {
        for (int j = 0; j < max_weight + 2; j++)
        {
            std::cout << list[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    int i{ count + 1 };
    int j{ max_weight + 1 };
    std::cout << "Combination: ";
    while (i - 1 > 0 and j > 0)
    {
        if (list[i - 1][j] == list[i][j])
        {
            i--;
            continue;
        }
        std::cout << i - 1 << " ";
        j -= weight_list[i];
        i--;
    }
}