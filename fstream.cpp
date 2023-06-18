#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

// функция для записи информации о товаре в файл
void writeToFile(fstream& file, const Product& product) {
    file << product.name << endl;
    file << product.quantity << endl;
    file << product.price << endl;
}

// функция для чтения информации о товаре из файла
Product readFromFile(fstream& file) {
    Product product;
    getline(file, product.name);
    file >> product.quantity;
    file >> product.price;
    file.ignore(); // игнорируем символ перевода строки после цены
    return product;
}

int main() {
    fstream file1("product1.txt", ios::in | ios::out);
    fstream file2("product2.txt", ios::in | ios::out);
    fstream file3("product3.txt", ios::in | ios::out);

    // узнаем, заполнены ли файлы
    bool isFile1Empty = file1.peek() == ifstream::traits_type::eof();
    bool isFile2Empty = file2.peek() == ifstream::traits_type::eof();
    bool isFile3Empty = file3.peek() == ifstream::traits_type::eof();

    if (isFile1Empty) {
        cout << "Введите информацию о товаре для файла product1.txt" << endl;
        for (int i = 0; i < 3; i++) {
            Product product;
            cout << "Введите название товара: ";
            getline(cin, product.name);
            cout << "Введите количество товара: ";
            cin >> product.quantity;
            cout << "Введите цену товара: ";
            cin >> product.price;
            file1.clear();
            file1.seekp(0, ios::end); // ставим указатель на конец файла
            writeToFile(file1, product);
            cin.ignore(); // игнорируем символ перевода строки после цены
        }
    }

    if (isFile2Empty) {
        cout << "Введите информацию о товаре для файла product2.txt" << endl;
        for (int i = 0; i < 3; i++) {
            Product product;
            cout << "Введите название товара: ";
            getline(cin, product.name);
            cout << "Введите количество товара: ";
            cin >> product.quantity;
            cout << "Введите цену товара: ";
            cin >> product.price;
            file2.clear();
            file2.seekp(0, ios::end);
            writeToFile(file2, product);
            cin.ignore();
        }
    }

    if (isFile3Empty) {
        cout << "Введите информацию о товаре для файла product3.txt" << endl;
        for (int i = 0; i < 3; i++) {
            Product product;
            cout << "Введите название товара: ";
            getline(cin, product.name);
            cout << "Введите количество товара: ";
            cin >> product.quantity;
            cout << "Введите цену товара: ";
            cin >> product.price;
            file3.clear();
            file3.seekp(0, ios::end);
            writeToFile(file3, product);
            cin.ignore();
        }
    }

    // вывод таблицы с информацией о товарах из всех файлов
    cout << "Id   Название    Кол-во   Цена" << endl;

    file1.seekg(0, ios::beg);
    file2.seekg(0, ios::beg);
    file3.seekg(0, ios::beg);

    for (int i = 1; i <= 3; i++) {
        Product product1, product2, product3;
        if (!isFile1Empty) {
            product1 = readFromFile(file1);
        }
        if (!isFile2Empty) {
            product2 = readFromFile(file2);
        }
        if (!isFile3Empty) {
            product3 = readFromFile(file3);
        }
        cout << i << ")   " << product1.name << "     " << product1.quantity << "      " << product1.price << endl;
        cout << "    " << product2.name << "     " << product2.quantity << "      " << product2.price << endl;
        cout << "    " << product3.name << "     " << product3.quantity << "      " << product3.price << endl;
    }

    file1.close();
    file2.close();
    file3.close();

    return 0;
}