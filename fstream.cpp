#include <iostream>
#include <fstream>

using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

void writeDataToFile(string filename, Product product) {
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        file << product.name << endl;
        file << product.quantity << endl;
        file << product.price << endl;
        file.close();
        cout << "Данные успешно записаны в файл " << filename << endl;
    }
    else {
        cout << "Не удалось открыть файл " << filename << endl;
    }
}

void printData(string filename) {
    ifstream file(filename);

    if (file.is_open()) {
        cout << "Id\tНазвание\tКол-во\tЦена" << endl;
        int id = 1;
        while (!file.eof()) { 
            Product product;
            file >> product.name >> product.quantity >> product.price;
            if (!product.name.empty()) { 
                cout << id << ")\t" << product.name << "\t\t" << product.quantity << "\t" << product.price << endl;
                id++;
            }
        }
        file.close();
    }
    else {
        cout << "Не удалось открыть файл " << filename << endl;
    }
}

int main() {
    string filename1 = "data1.txt";
    string filename2 = "data2.txt";
    string filename3 = "data3.txt";

    cout << "Меню:" << endl;
    cout << "1 - Записать товар в файл " << filename1 << endl;
    cout << "2 - Записать товар в файл " << filename2 << endl;
    cout << "3 - Записать товар в файл " << filename3 << endl;
    cout << "4 - Считать данные из файлов и вывести таблицу" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
        {
            Product product;
            cout << "Введите название товара: ";
            cin >> product.name;
            cout << "Введите количество: ";
            cin >> product.quantity;
            cout << "Введите цену: ";
            cin >> product.price;
            writeDataToFile(filename1, product);
            break;
        }
        case 2:
        {
            Product product;
            cout << "Введите название товара: ";
            cin >> product.name;
            cout << "Введите количество: ";
            cin >> product.quantity;
            cout << "Введите цену: ";
            cin >> product.price;
            writeDataToFile(filename2, product);
            break;
        }
        case 3:
        {
            Product product;
            cout << "Введите название товара: ";
            cin >> product.name;
            cout << "Введите количество: ";
            cin >> product.quantity;
            cout << "Введите цену: ";
            cin >> product.price;
            writeDataToFile(filename3, product);
            break;
        }
        case 4:
        {
            cout << "Данные из файла " << filename1 << ":" << endl;
            printData(filename1);
            
            cout << "Данные из файла " << filename2 << ":" << endl;
            printData(filename2);
            
            cout << "Данные из файла " << filename3 << ":" << endl;
            printData(filename3);
            
            break;
        }
        default:
            cout << "Неправильный выбор" << endl;
            break;
    }

    return 0;
}
