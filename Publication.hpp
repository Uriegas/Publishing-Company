#include <iostream>

class Publication{
    private:
        std::string title;
        float price;
    public:
        void getData(void);
        void putdata(void);
};

class Book: Publication{
    private:
        int page_counter;
    public:
        void getData(void);
        void putdata(void);
};

class Tape:Publication{
    private:
        float playing_time;
    public:
        void getData(void);
        void putdata(void);
};