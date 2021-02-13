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

void Sales::getData(void){
    for(int i = 0; i < 12; i++){
        std::cout << "Enter " + std::to_string(i+1) + " month sales amount (quantity): ";
        std::cin >> sales_amount[i];
    }
}

std::string Sales::putData(void){
    std::string out;
    for(int i = 0; i < 12; i++)
        out += "Sales in month " + std::to_string(i+1) + " are: " + std::to_string(sales_amount[i]) + '\n';
    return out;
}

void Book::getData(void){
    Publication::getData();
    Sales::getData();
    std::cout << "Enter number of pages: ";
    std::cin >> page_counter;
}

std::string Book::putData(void){
    return Publication::putData() + Sales::putData() + "Number of pages: " + std::to_string(page_counter) + '\n';
}

void Tape::getData(void){
    Publication::getData();
    Sales::getData();
    std::cout << "Enter the playing time(minutes): ";
    std::cin >> playing_time;
}

std::string Tape::putData(void){
    return Publication::putData() + Sales::putData() + "Playing Time (min): " + std::to_string(playing_time) + '\n';
}

void Disk::getData(void){
    char buff;
    Publication::getData();
    Sales::getData();
    do{
        std::cout << "Enter the disk type (d = dvd, c = cd):";
        std::cin >> buff;
    }
    while(!(buff == 'c' || buff == 'd'));
    type = (disk_type)buff;
}

std::string Disk::putData(void){
    return Publication::putData() + Sales::putData() + "Disk Type: " + (type == CD ? "CD" : "DVD") + '\n';
}

void Interface::menu(){
    std::cout << "This a publications sales store (books, tapes and disks)";

    while (true){
        std::string buffer;
        std::cout << "1. " << "Add publication" << '\n'
                  << "2. " << "Add book" << '\n'
                  << "3. " << "Add Tape" << '\n'
                  << "4. " << "Add Disk" << '\n'
                  << "5. " << "Quit" << std::endl;

        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> selection;

        switch (selection){
        case 1:
            break;
        
        default:
            break;
        }
    }
    
}