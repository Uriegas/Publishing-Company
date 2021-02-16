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

float Sales::getAnnualSales(){
    float tmp = 0;
    for(auto x : sales_amount)
        tmp += x;
    return tmp;
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

void Interface::viewAll(){
    for(Book x : books)
        std::cout << x.putData();
    for(Tape x : tapes)
        std::cout << x.putData();
    for(Disk x : disks)
        std::cout << x.putData();
}

void Interface::salesMenu(){
    while(true){
        std::cout << "1. " << "Anual Books Sales" << '\n'
                  << "2. " << "Anual Tapes Sales" << '\n'
                  << "3. " << "Anual Disks Sales" << '\n'
                  << "4. " << "Quit" << '\n';
        std::cin.ignore();
        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> selection;
        std::cout << selection;

        switch (selection){
        case 1:{
            float sales = 0;
            for( Sales x : books)
                sales += x.getAnnualSales();
            break;
        }
        case 2:{
            float sales = 0;
            for( Sales x : tapes)
                sales += x.getAnnualSales();
            break;
        }
        case 3:{
            float sales = 0;
            for( Sales x : disks)
                sales += x.getAnnualSales();
            break;
        }
        case 4:
            return;
        default:
            break;
        }
    }
}

void Interface::menu(){
    std::cout << "This a publications sales store (books, tapes and disks)\n";

    while (true){
        std::cout << "1. " << "Add Book" << '\n'
                  << "2. " << "Add Tape" << '\n'
                  << "3. " << "Add Disk" << '\n'
                  << "4. " << "View All" << '\n'
                  << "5. " << "View Revenue" << '\n'
                  << "6. " << "Quit" << '\n';
        std::cin.ignore();
        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> selection;
        std::cout << selection;

        switch (selection){
        case 1:{
            Book tmp;
            tmp.getData();
            books.push_back(tmp);
            break;
        }
        case 2:{
            Tape tmp;
            tmp.getData();
            tapes.push_back(tmp);
            break;
        }
        case 3:{
            Disk tmp;
            tmp.getData();
            disks.push_back(tmp);
            break;
        }
        case 4:{
            viewAll();
            break;
        }
        case 5:{
            salesMenu();
            break;
        }
        case 6:
            return;
        default:
            break;
        }
    }
    
}