#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string* alignColumns(const string* input, int numRows) {
    int maxColumnSize = 0;

    // Находим максимальную ширину столбца
    for (int i = 0; i < numRows; i++) {
        stringstream ss(input[i]);
        string column;

        while (getline(ss, column, '$')) {
            if (column.size() > maxColumnSize) {
                maxColumnSize = column.size();
            }
        }
    }

    string* alignedText = new string[maxColumnSize];

    // Выравниваем каждый столбец путем добавления пробелов
    for (int i = 0; i < numRows; i++) {
        stringstream ss(input[i]);
        string column;
        int colIndex = 0;

        while (getline(ss, column, '$')) {
            // Добавляем пробелы для выравнивания
            int diff = maxColumnSize - column.size();
            alignedText[colIndex] += column + string(diff, ' ');
            colIndex++;
        }
    }

    return alignedText;
}

int main() {
    string testText[] = {
        "Given$a$text$file$of$many$lines",
        "where$fields$within$a$line$",
        "are$delineated$by$a$single$\"dollar\"$character",
        "write$a$program",
        "that$aligns$each$column$of$fields",
        "by$ensuring$that$words$in$each$",
        "column$are$separated$by$at$least$one$space.",
        "Further,$allow$for$each$word$in$a$column$to$be$either$left$",
        "justified,$right$justified",
        "or$center$justified$within$its$column."
    };

    int numRows = sizeof(testText) / sizeof(testText[0]);

    string* alignedText = alignColumns(testText, numRows);

    for (int i = 0; i < numRows; i++) {
        cout << alignedText[i] << endl;
    }

    delete[] alignedText;

    return 0;
}