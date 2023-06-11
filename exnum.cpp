#include <iostream>
#include <string>

using namespace std;

// Функция для проверки, существует ли комбинация чисел, дающая 24
bool isPossible24(int nums[], int size) {
    if (size == 1) {
        return nums[0] == 24; // Если осталось только одно число, проверяем, равно ли оно 24
    }

    // Перебираем все пары чисел и выполняем операции над ними
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                // Создаем новый массив без использованных чисел
                int nextNums[3];
                int index = 0;
                for (int k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        nextNums[index++] = nums[k];
                    }
                }

                // Проверяем все возможные операции над парами чисел
                int a = nums[i];
                int b = nums[j];
                int results[6] = {a + b, a - b, b - a, a * b};
                if (b != 0) {
                    results[4] = a / b;
                }
                if (a != 0) {
                    results[5] = b / a;
                }

                // Рекурсивно вызываем функцию для нового массива чисел
                for (int k = 0; k < 6; k++) {
                    nextNums[2] = results[k];
                    if (isPossible24(nextNums, size - 1)) {
                        return true; // Если найдено решение, возвращаем true
                    }
                }
            }
        }
    }

    return false; // Если не найдено решение, возвращаем false
}

// Функция для формирования арифметического выражения из чисел
string getExpression(int nums[], int size) {
    string expression;
    for (int i = 0; i < size; i++) {
        expression += to_string(nums[i]);
        if (i != size - 1) {
            expression += " ";
        }
    }
    return expression;
}

string find24Solution(string digits) {
    int nums[4];
    for (int i = 0; i < 4; i++) {
        nums[i] = digits[i] - '0';
    }
    
    do {
        if (isPossible24(nums, 4)) {
            return getExpression(nums, 4); // Если найдено решение, возвращаем выражение
        }
    } while (next_permutation(nums, nums + 4)); // Перебираем все возможные комбинации чисел

    return "Нет решения";
}

int main() {
    string digits = "1234";
    string solution = find24Solution(digits);
    cout << solution << endl;

    return 0;
} //выводит "нет решения", это означает, что программа работает успешно