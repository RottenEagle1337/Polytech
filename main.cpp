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
    std:: cout << "1. ������� ����������� ����������.\n"<<
    "2. ����� ��������� ����������� ����������.\n"<<
    "3. ���� ��������� (�����) ��������� � ����������.\n"<<
    "4. ����� ��������� (�����) ��������� �� ������� �� �������.\n"<<
    "5. ����� �� ����� ���� ����������� ��������� ������� ��������.\n"<<
    "6. ����� � ������� �������� �������� � �������� ������� � ���� �� ��������.\n"<< 
    "7. ����� � ������� ��������� � ����������� ��������� ��������� ����.\n"<<
    "8. ���������� ������� �������� � ������� �����������/�������� ��������� ����\n"<<
    "9. ������� ������ ����� � ���������� ���� ������ (������� ����������� ���������).\n"<<
    "0. ������� ������ � ���� ����������� ���� ������ (������� ����������� ���������).\n"<<
    "s: �����." <<std::endl;

    char userAnswer;
    std:: cout << "\n������� ����� �������: "; std::cin >> userAnswer;

    Negotiator person;

    while (userAnswer!='s')
    {
        switch (userAnswer)
        {
        case '1':
        {
            //�������� �������� �� �������
            std::cout<<"������: "<<std::endl; std::cin>>elementIndex;
            database -> Delete(elementIndex);
            std::cout<<"�������!" << std::endl;
            }
            break;
        case '2':
            {
                int index = database->FindEmpty();
                std::cout <<"������ ������� �������� "<< index <<std::endl;
            }   
            break;

        case '3':
            {
                std::cout <<"�� ������ ������� ����� ����������?: "<<std::endl; std::cin>>elementIndex;
                std:: cout << "���: "; std::cin >> person.personInitials;
                std:: cout << "���������� �����������: "; std::cin >> person.conversationsCount;
                std::cout << "������������ �����������: "; std::cin >> person.conversation.duration;
                std::cout << "���� �����������: "; std::cin >> person.conversation.date;
                database -> Add(elementIndex, person);
                std::cout<< "���������\n";
            }
            break;

        case '4':
            {
             //��������� �������� �� �������
            
            std::cout<<"�� ������ ������� �������� �������?: "; std::cin>>elementIndex;
            Negotiator outputByIndex = database->Get(elementIndex);
            DisplayData(outputByIndex);
            }
            break;
        case '5':
            {
            //��������� ���� ���������
            std::vector<Negotiator> all = database->GetAll();
            for (size_t i = 0; i < all.size(); i++)
                 DisplayData(all[i]);
            }
            break;
        case '6':
            {
                //����� ����������
            int fieldNum;
            std::cout << "�� ������ ���� ������?\n"<<
            "1: ���\n"<< 
            "2: ���������� �����������\n"<<
            "3: ������������ �����������\n"<<
            "4: ���� �����������"<<std::endl;
            std::cin >> fieldNum;
 
            Negotiator *result;
            int searchValue;
            char* searchString;
            
            if (fieldNum == 2 || fieldNum == 3){
                std::cout << "������� �������� ��� ���������: "; std::cin >> searchValue; 
                result = fieldNum == 2 ? database->FindNearestInt<0>(searchValue) : database->FindNearestInt<1>(searchValue);
            }
            else {
                std::cout << "������� ������ ��� ���������: "; std::cin >> searchString; 
                result = fieldNum == 1 ? database->FindNearestString<0>(searchString):database->FindNearestString<1>(searchString);
            }

            if(result == NULL) 
                std::cout << "�� ������� 0(-_-)0" << std::endl;
            else    
                 DisplayData(*result);
            }
            
            break;
        case '7':
            {
                int fieldNum;
                std::cout << "�� ������ ���� ������?\n"<<
                "1: ���\n"<<
                "2: ���������� �����������\n"<<
                "3: ������������ �����������\n"<<
                "4: ���� �����������"<<std::endl;
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
                else std::cout<<"��� ������������";
            }
            
            break;
        case '8':
            {
                int fieldNum;
                std::cout << "�� ������ ���� �����������?\n"<<
                "1: ���\n"<<
                "2: ���������� �����������\n"<<
                "3: ������������ �����������\n"<<
                "4: ���� �����������"<<std::endl;
                std::cin >> fieldNum;
                std::vector<Negotiator> Sorted;
                char direction;
                bool _dirAsc;
                std::cout<< "����������� �� ����������� ��� �� ��������: 0/1\n"; std::cin >> direction;
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
                std::cout << "������������� �� �����!"<<std::endl;
            }
            break;

            case '0':
            {
                database->Save();
                std::cout << "���������!"<<std::endl;
            }
            break;

        default:
            std::cout << "�������� ����� �������";
            break;
        }
        std:: cout << "����� �������: "; std::cin >> userAnswer;
        }
    
    return 0;
};

