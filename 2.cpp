#include <iostream>
#include <vector>
using namespace std;

vector<int> finalDoorState(int numDoors) {
    vector<bool> doors(numDoors, false); // Создание вектора doors размером номер двери и инициализация всех элементов значением закрыто

    for (int i = 1; i <= numDoors; i++) {
        for (int j = i; j <= numDoors; j += i) {
            doors[j - 1] = !doors[j - 1]; // Переключение состояния двери с помощью отрицания в векторе doors
        }
    }

    vector<int> openDoors; // Создание пустого вектора для хранения номеров открытых дверей

    for (int i = 0; i < numDoors; i++) {
        if (doors[i]) {
            openDoors.push_back(i + 1); // Добавление номера открытой двери (i + 1) в вектор openDoors
        }
    }

    return openDoors; // Возврат вектора с номерами открытых дверей
}

int main() {
    using namespace std; 

    int numDoors = 100; // Количество дверей

    vector<int> result = finalDoorState(numDoors); // Вызов функции для получения результата

    for (int i = 0; i < result.size(); i++) { // Цикл перебора элементов вектора result с использованием индексов
        int door = result[i]; // Получение элемента вектора с индексом i
        cout << door << " "; // Вывод каждого элемента (номера открытой двери) на экран, разделенного пробелом
    }
    cout << endl; 

    return 0; 
}