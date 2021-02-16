#include <iostream>
enum disk_type{CD = 'c', DVD = 'd'};

class Publication{
    private:
        std::string title;
        float price;
    public:
        virtual void getData(void);
        virtual std::string putData(void);
};

class Sales{
    private:
        //Quantity of items sold in a year
        int sales_amount[12];
    public:
        virtual void getData(void);
        virtual std::string putData(void);
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

class Interface: private Book, private Tape, private Disk{
    private:
        int selection;
    public:
        void menu();
};