#include "Publication.hpp"

void Publication::getData(void){
    std::cout << "Enter the publication title: ";
    std::cin >> std::ws;
    std::getline(std::cin, title);
    std::cout << "Enter the price: ";
    std::cin >> price;
}

std::string Publication::putData(void){
    return "Title: " + title + '\n' + "Price: " + std::to_string(price) + '\n';
}

void Book::getData(void){
    Publication::getData();
    std::cout << "Enter number of pages: ";
    std::cin >> page_counter;
}

std::string Book::putData(void){
    return Publication::putData() + "Number of pages: " + std::to_string(page_counter) + '\n';
}