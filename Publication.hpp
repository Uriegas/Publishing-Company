#include <iostream>
#include <sstream>
#include <vector>

enum disk_type{CD = 'c', DVD = 'd'};

class Publication{
    private:
        std::string title;
        float price;
    public:
        virtual void getData(void);
        virtual std::string putData(void);
        float getPrice(){return price;}
};

class Sales{
    private:
        //Quantity of items sold in a year
        float sales_amount[12];
        float total_sales;
        void ComputeSales();
    public:
        Sales(): total_sales(0){};
        float getAnnualSales();
        void getData(void);
        std::string putData(void);
};

class Book: public Publication, public Sales{
    private:
        int page_counter;
    public:
        void getData (void)override;
        std::string putData(void)override;
};

class Tape: public Publication, public Sales{
    private:
        float playing_time;
    public:
        void getData(void)override;
        std::string putData(void)override;
};

class Disk: public Publication, public Sales{
    private:
        disk_type type;
    public:
        void getData(void)override;
        std::string putData(void)override;
};

class Interface{
    private:
        std::string buffer;
        int selection;
        std::vector<Publication> publications;
        std::vector<Book> books;
        std::vector<Tape> tapes;
        std::vector<Disk> disks;
        float gross_total_sales [3];
        void viewAll();
        void salesMenu();
        void getAnnualSales();
    public:
        Interface(): gross_total_sales{0,0,0}{};
        void menu();
};