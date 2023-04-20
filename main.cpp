#include <iostream>
#include "database.cpp"
#include <vector>
#include <tuple>
#include <string.h>
#include <stdio.h>
#include <fstream>

void DisplayData(Negotiator person){
    std::cout << person.personInitials << " " << person.conversationsCount<< " "
   
    << person.conversation.duration << " " << person.conversation.date << std::endl;
}



int main(){
    setlocale(LC_ALL, "Russian");

    int dbSize = 7;
    std::string dbName = "myDataBase.bin";

    
    DataBase *database = new DataBase(dbName, dbSize);
    
    int elementIndex;
    std:: cout << "1. Очистка структурных переменных.\n"<<
    "2. Поиск свободной структурной переменной.\n"<<
    "3. Ввод элементов (полей) структуры с клавиатуры.\n"<<
    "4. Вывод элементов (полей) структуры на монитор по индексу.\n"<<
    "5. Вывод на экран всех заполненных элементов массива структур.\n"<<
    "6. Поиск в массиве структур элемента с наиболее близким к нему по значению.\n"<< 
    "7. Поиск в массиве структуры с минимальным значением заданного поля.\n"<<
    "8. Сортировка массива структур в порядке возрастания/убывания заданного поля\n"<<
    "9. Функция чтения файла с содержимым базы данных (массива структурных элементов).\n"<<
    "0. Функция записи в файл содержимого базы данных (массива структурных элементов).\n"<<
    "s: выход." <<std::endl;

    char userAnswer;
    std:: cout << "\nВведите номер задания: "; std::cin >> userAnswer;

    Negotiator person;

    while (userAnswer!='s')
    {
        switch (userAnswer)
        {
        case '1':
        {
            //удаление элемента по индексу
            std::cout<<"Индекс: "<<std::endl; std::cin>>elementIndex;
            database -> Delete(elementIndex);
            std::cout<<"Удалено!" << std::endl;
            }
            break;
        case '2':
            {
                int index = database->FindEmpty();
                std::cout <<"Индекс пустого элемента "<< index <<std::endl;
            }   
            break;

        case '3':
            {
                std::cout <<"По какому индексу будет находиться?: "<<std::endl; std::cin>>elementIndex;
                std:: cout << "ФИО: "; std::cin >> person.personInitials;
                std:: cout << "Количество конференций: "; std::cin >> person.conversationsCount;
                std::cout << "Длительность конференции: "; std::cin >> person.conversation.duration;
                std::cout << "Дата конференции: "; std::cin >> person.conversation.date;
                database -> Add(elementIndex, person);
                std::cout<< "Добавлено\n";
            }
            break;

        case '4':
            {
             //получение элемента по индексу
            
            std::cout<<"По какому индексу получить элемент?: "; std::cin>>elementIndex;
            Negotiator outputByIndex = database->Get(elementIndex);
            DisplayData(outputByIndex);
            }
            break;
        case '5':
            {
            //получение всех элементов
            std::vector<Negotiator> all = database->GetAll();
            for (size_t i = 0; i < all.size(); i++)
                 DisplayData(all[i]);
            }
            break;
        case '6':
            {
                //поиск ближайшего
            int fieldNum;
            std::cout << "По какому полю искать?\n"<<
            "1: ФИО\n"<< 
            "2: количество конференций\n"<<
            "3: длительность конференции\n"<<
            "4: дата конференции"<<std::endl;
            std::cin >> fieldNum;
 
            Negotiator *result;
            int searchValue;
            char* searchString;
            
            if (fieldNum == 2 || fieldNum == 3){
                std::cout << "Введите значение для сравнения: "; std::cin >> searchValue; 
                result = fieldNum == 2 ? database->FindNearestInt<0>(searchValue) : database->FindNearestInt<1>(searchValue);
            }
            else {
                std::cout << "Введите строку для сравнения: "; std::cin >> searchString; 
                result = fieldNum == 1 ? database->FindNearestString<0>(searchString):database->FindNearestString<1>(searchString);
            }

            if(result == NULL) 
                std::cout << "Не найдено 0(-_-)0" << std::endl;
            else    
                 DisplayData(*result);
            }
            
            break;
        case '7':
            {
                int fieldNum;
                std::cout << "По какому полю искать?\n"<<
                "1: ФИО\n"<<
                "2: количество конференций\n"<<
                "3: длительность конференции\n"<<
                "4: дата конференции"<<std::endl;
                std::cin >> fieldNum;
                Negotiator *result;
                switch (fieldNum)
                {
                case 1:             
                    result = database->FindMin<0>();
                break;
                case 2:
                     result = database->FindMin<1>();
                break;
                case 3:
                     result = database->FindMin<2>();
                break;
                case 4:
                     result = database->FindMin<3>();
                break;
                }
                
                if (result != NULL)
                    DisplayData(*result);
                else std::cout<<"Нет минимального";
            }
            
            break;
        case '8':
            {
                int fieldNum;
                std::cout << "По какому полю сортировать?\n"<<
                "1: ФИО\n"<<
                "2: количество конференций\n"<<
                "3: длительность конференции\n"<<
                "4: дата конференции"<<std::endl;
                std::cin >> fieldNum;
                std::vector<Negotiator> Sorted;
                char direction;
                bool _dirAsc;
                std::cout<< "Сортировать по возрастанию или по убыванию: 0/1\n"; std::cin >> direction;
                _dirAsc = direction == '0' ? true : false;
                
                switch (fieldNum)
                {
                case 1:             
                    database->SortBy<0>(_dirAsc);
                break;
                case 2:
                     database->SortBy<1>(_dirAsc);
                break;
                case 3:
                     database->SortBy<2>(_dirAsc);
                break;
                case 4:
                     database->SortBy<3>(_dirAsc);
                break;
                }
                
                Sorted = database->GetAll();
                for (size_t i = 0; i < Sorted.size(); i++)
                     DisplayData(Sorted[i]);
            }
            break;
            case '9':
            {
                delete database;
                database = new DataBase(dbName, dbSize);
                database-> Restore();
                std::cout << "Восстановлено из файла!"<<std::endl;
            }
            break;

            case '0':
            {
                database->Save();
                std::cout << "Сохранено!"<<std::endl;
            }
            break;

        default:
            std::cout << "Неверный номер задания";
            break;
        }
        std:: cout << "Номер задания: "; std::cin >> userAnswer;
        }
    
    return 0;
};

