#include <iostream>
#include "Container.h"
#include "doublelinked_list.h"
#include "linked_list.h"

int main()
{
    linked_list myList;

    // Добавляем элементы в список
    myList.push(1.0);
    myList.push(2.0);
    myList.push(3.0);

    myList.insert(0, 100);

    // Выводим список
    myList.showlist();

    std::cout << "Value:"; std::cout << myList[2] << std::endl;
    std::cout << "Size:"; std::cout << myList.getsize();
    std::cout << "===========================" << std::endl;
}

