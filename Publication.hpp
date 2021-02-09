#include <iostream>

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
        float sales_3months [3];
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