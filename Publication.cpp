#include "Publication.hpp"

void Publication::getData(void){
    std::cout << "Enter the publication title: ";
    std::getline(std::cin, title);
    std::cout << "\nEnter the price: ";
    std::cin >> price;
}

std::string Publication::putData(void){
    return "Hola";
}