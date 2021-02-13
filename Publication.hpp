#include <iostream>
enum disk_type{CD = 'c', DVD = 'd'};

class Publication{
    private:
        std::string title;
        float price;
    public:
        void getData(void);
        std::string putData(void);
};

class Sales{
    private:
        //Quantity of items sold in a year
        int sales_amount[12];
    public:
        void getData(void);
        std::string putData(void);
};

class Book: Publication, Sales{
    private:
        int page_counter;
    public:
        void getData(void);
        std::string putData(void);
};

class Tape:Publication, Sales{
    private:
        float playing_time;
    public:
        void getData(void);
        std::string putData(void);
};

class Disk: Publication, Sales{
    private:
        disk_type type;
    public:
        void getData(void);
        std::string putData(void);
};

class Interface: Book, Tape, Disk{
    private:
        int selection;
    public:
        void menu();
};