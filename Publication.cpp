#include "Publication.hpp"

void Publication::getData(void){
    std::string tmp;
    std::cout << "Enter the publication title: ";
    std::getline(std::cin, title);
    std::cout << "Enter the price: ";
    std::getline(std::cin, tmp);
    std::stringstream(tmp) >> price;
}

std::string Publication::putData(void){
    return "Title: " + title + '\n' + "Price: " + std::to_string(price) + '\n';
}

void Sales::ComputeSales(){
    for(auto x : sales_amount)
        total_sales += x;
}

float Sales::getAnnualSales(){
    return total_sales;
}

void Sales::getData(void){
    std::string tmp;
    for(int i = 0; i < 12; i++){
        std::cout << "Enter " + std::to_string(i+1) + " month sales amount (quantity): ";
        std::getline(std::cin, tmp);
        std::stringstream(tmp) >> sales_amount[i];
    }
    ComputeSales();//Calculate annual sales after getting data
}

std::string Sales::putData(void){
    std::string out;
    for(int i = 0; i < 12; i++)
        out += "Sales in month " + std::to_string(i+1) + " are: " + std::to_string(sales_amount[i]) + '\n';
    return out;
}

void Book::getData(void){
    std::string tmp;
    Publication::getData();
    Sales::getData();
    std::cout << "Enter number of pages: ";
    std::getline(std::cin, tmp);
    std::stringstream(tmp) >> page_counter;
}

std::string Book::putData(void){
    return Publication::putData() + Sales::putData() + "Number of pages: " + std::to_string(page_counter) + '\n';
}

void Tape::getData(void){
    std::string tmp;
    Publication::getData();
    Sales::getData();
    std::cout << "Enter the playing time(minutes): ";
    std::getline(std::cin, tmp);
    std::stringstream(tmp) >> playing_time;
}

std::string Tape::putData(void){
    return Publication::putData() + Sales::putData() + "Playing Time (min): " + std::to_string(playing_time) + '\n';
}

void Disk::getData(void){
    std::string buff;
    Publication::getData();
    Sales::getData();
    do{
        std::cout << "Enter the disk type (d = dvd, c = cd):";
        std::getline(std::cin, buff);
    }
    while(!(buff == "c" || buff == "d"));
    type = (disk_type)buff[1];
}

std::string Disk::putData(void){
    return Publication::putData() + Sales::putData() + "Disk Type: " + (type == CD ? "CD" : "DVD") + '\n';
}

void Interface::viewAll(){
    if(!books.empty())
        for(Book x : books)
            std::cout << x.putData();
    if(!tapes.empty())
        for(Tape x : tapes)
            std::cout << x.putData();
    if(!disks.empty())
        for(Disk x : disks)
            std::cout << x.putData();
}

void Interface::getAnnualSales(){
    for( Sales x : books)
        gross_total_sales[0] += x.getAnnualSales();
    for( Sales x : tapes)
        gross_total_sales[1] += x.getAnnualSales();
    for( Sales x : disks)
        gross_total_sales[2] += x.getAnnualSales();
}

void Interface::salesMenu(){
    getAnnualSales();
    while(true){
        std::cout << "-------Anual Sales-------" << '\n'
                  << "1. " << "Anual Book Sales" << '\n'
                  << "2. " << "Anual Tape Sales" << '\n'
                  << "3. " << "Anual Disk Sales" << '\n'
                  << "4. " << "Total Sales" << '\n'
                  << "5. " << "Quit" << std::endl;

        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> selection;

        switch (selection){
            case 1:{
                std::cout << "Anual Book Sales are: " << gross_total_sales[0] << '\n';
                break;
            }
            case 2:{
                float sales = 0;
                for( Sales x : tapes)
                    sales += x.getAnnualSales();
                std::cout << "Anual Tape Sales are: " << gross_total_sales[1] << '\n';
                break;
            }
            case 3:{
                std::cout << "Anual Disks Sales are: " << gross_total_sales[2] << '\n';
                break;
            }
            case 4:{
                float total;
                for( auto x : gross_total_sales )
                    total += x;
                std::cout << "Total Store Sales: " << total << '\n';
                break;
            }
            case 5:
                return;
            default:
                break;
        }
    }
}

void Interface::menu(){
    while (true){
        std::cout << "This a publications sales store (books, tapes and disks)\n"
                  << "1. " << "Add Book" << '\n'
                  << "2. " << "Add Tape" << '\n'
                  << "3. " << "Add Disk" << '\n'
                  << "4. " << "View All" << '\n'
                  << "5. " << "View Revenue" << '\n'
                  << "6. " << "Quit" << std::endl;
        std::cin.clear();
        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> selection;

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