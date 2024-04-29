#include <iostream>
#include "Container.h"
#include "doublelinked_list.h"
#include "linked_list.h"

int main()
{

    //linked_list myList;

    //// Добавляем элементы в список
    //myList.push(1.0);
    //myList.push(2.0);
    //myList.push(3.0);
    //myList.insert(0, 100);
    //myList.insert(0, 100);

    //// Выводим список
    //myList.showlist();

    //std::cout << "Value:"; std::cout << myList[2] << std::endl;
    //std::cout << "Size:"; std::cout << myList.getsize();
    //std::cout << "===========================" << std::endl;

    doublelinked_list lst;
    doublelinked_list lst2;

    lst.unshift(3);
    lst.unshift(2);

    lst.push(1);
    lst.push(4);

    lst.showlist();
    std::cout << "===========================" << std::endl;
    std::cout << lst[2] << std::endl;
    std::cout << "===========================" << std::endl;
    lst2 = lst;
    lst.remove(2);

    lst2.showlist();


}

