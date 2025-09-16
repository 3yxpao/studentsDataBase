#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>

// Подключаем структуру Student
struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Прототипы функций из основного файла
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
int countStudents(const std::vector<Student>& database);

// Функция для тестирования
void runTests() {
    std::cout << "Запуск тестов...\n";
    
    // Тест 1: Проверка подсчета студентов в пустой базе
    std::vector<Student> emptyDB;
    assert(countStudents(emptyDB) == 0);
    std::cout << "Тест 1 пройден: Пустая база данных\n";
    
    // Тест 2: Проверка добавления одного студента
    std::vector<Student> singleStudentDB;
    
    // Имитируем ввод для одного студента
    std::istringstream input1("Иван\n20\nИнформатика\n4.5\n");
    std::cin.rdbuf(input1.rdbuf());
    
    addStudent(singleStudentDB);
    assert(countStudents(singleStudentDB) == 1);
    assert(singleStudentDB[0].name == "Иван");
    assert(singleStudentDB[0].age == 20);
    assert(singleStudentDB[0].major == "Информатика");
    assert(singleStudentDB[0].gpa == 4.5);
    std::cout << "Тест 2 пройден: Добавление одного студента\n";
    
    // Тест 3: Проверка добавления нескольких студентов
    std::vector<Student> multiStudentDB;
    
    // Первый студент
    std::istringstream input2("Мария\n19\nФизика\n4.7\n");
    std::cin.rdbuf(input2.rdbuf());
    addStudent(multiStudentDB);
    
    // Второй студент
    std::istringstream input3("Петр\n21\nМатематика\n4.3\n");
    std::cin.rdbuf(input3.rdbuf());
    addStudent(multiStudentDB);
    
    assert(countStudents(multiStudentDB) == 2);
    assert(multiStudentDB[0].name == "Мария");
    assert(multiStudentDB[1].name == "Петр");
    std::cout << "Тест 3 пройден: Добавление нескольких студентов\n";
    
    // Тест 4: Проверка корректности данных
    assert(multiStudentDB[0].age == 19);
    assert(multiStudentDB[0].major == "Физика");
    assert(multiStudentDB[1].age == 21);
    assert(multiStudentDB[1].major == "Математика");
    std::cout << "Тест 4 пройден: Корректность данных студентов\n";
    
    // Тест 5: Проверка функции отображения (косвенная проверка через наличие данных)
    assert(!multiStudentDB.empty());
    assert(!multiStudentDB[0].name.empty());
    assert(!multiStudentDB[0].major.empty());
    assert(multiStudentDB[0].gpa >= 0 && multiStudentDB[0].gpa <= 5.0);
    std::cout << "Тест 5 пройден: Проверка целостности данных\n";
    
    // Тест 6: Проверка граничных значений GPA
    std::vector<Student> edgeCaseDB;
    
    std::istringstream input4("Анна\n22\nХимия\n0.0\n");
    std::cin.rdbuf(input4.rdbuf());
    addStudent(edgeCaseDB);
    
    std::istringstream input5("Алексей\n23\nБиология\n5.0\n");
    std::cin.rdbuf(input5.rdbuf());
    addStudent(edgeCaseDB);
    
    assert(edgeCaseDB[0].gpa == 0.0);
    assert(edgeCaseDB[1].gpa == 5.0);
    std::cout << "Тест 6 пройден: Граничные значения GPA\n";
    
    std::cout << "Все тесты успешно пройдены!\n";
}

// Модифицированная функция addStudent для тестирования
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cin >> student.name;
    std::cin >> student.age;
    std::cin >> student.major;
    std::cin >> student.gpa;

    database.push_back(student);
}

// Функция для подсчета студентов
int countStudents(const std::vector<Student>& database) {
    return database.size();
}

int main() {
    // Запуск тестов
    runTests();
    
    // Основная логика программы (можно закомментировать для чистого тестирования)
    std::vector<Student> database;
    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Показать количество студентов\n";
        std::cout << "4. Запустить тесты\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                // displayStudents(database); // Нужно реализовать
                break;
            case 3:
                std::cout << "Количество студентов: " << countStudents(database) << "\n";
                break;
            case 4:
                runTests();
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
