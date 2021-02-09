#include "Publication.hpp"

void Publication::getData(void){
    std::cout << "Enter the publication title: ";
    std::getline(std::cin, title);
    std::cout << "Enter the price: ";
    std::cin >> price;
}

std::string Publication::putData(void){
    return "Title: " + title + '\n' + "Price: " + std::to_string(price) + '\n';
}