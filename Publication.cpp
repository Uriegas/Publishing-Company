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

void Tape::getData(void){
    Publication::getData();
    std::cout << "Enter the playing time(minutes): ";
    std::cin >> playing_time;
}

std::string Tape::putData(void){
    return Publication::putData() + "Playing Time (min): " + std::to_string(playing_time) + '\n';
}

void Sales::getData(void){
    for(int i = 0; i < 3; i++){
        std::cout << "Enter " + std::to_string(i+1) + " month sales amount: ";
        std::cin >> sales_3months[i];
    }
}

std::string Sales::putData(void){
    std::string out;
    for(int i = 0; i < 3; i++)
        out += "Sales in month " + std::to_string(i+1) + " are: " + std::to_string(sales_3months[i]) + '\n';
    return out;
}