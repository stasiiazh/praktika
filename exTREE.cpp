#include <iostream>
#include <vector>
using namespace std;

vector<int> finalDoorState(int numDoors) {
    vector<bool> doors(numDoors, false); // Создание вектора doors размером numDoors и инициализация всех элементов значением false (закрыто)

    for (int i = 1; i <= numDoors; i++) {
        for (int j = i; j <= numDoors; j += i) {
            doors[j - 1] = !doors[j - 1]; // Переключение состояния двери с помощью оператора отрицания (!) в векторе doors
        }
    }

    vector<int> openDoors; // Создание пустого вектора openDoors для хранения номеров открытых дверей

    for (int i = 0; i < numDoors; i++) {
        if (doors[i]) {
            openDoors.push_back(i + 1); // Добавление номера открытой двери (i + 1) в вектор openDoors
        }
    }

    return openDoors; // Возврат вектора openDoors с номерами открытых дверей
}

int main() {
    using namespace std; // Директива using для использования пространства имен std

    int numDoors = 100; // Количество дверей

    vector<int> result = finalDoorState(numDoors); // Вызов функции finalDoorState для получения результата

    for (int i = 0; i < result.size(); i++) { // Цикл перебора элементов вектора result с использованием индексов
        int door = result[i]; // Получение элемента вектора с индексом i
        cout << door << " "; // Вывод каждого элемента (номера открытой двери) на экран, разделенного пробелом
    }
    cout << endl; // Переход на новую строку

    return 0; // Завершение программы
}