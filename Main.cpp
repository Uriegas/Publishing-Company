#include "Publication.hpp"

int main(void){
    Publication mipublicacion = Publication();
    mipublicacion.getData();
    std::cout << mipublicacion.putData();

    Book harrypopote = Book();
    harrypopote.getData();
    std::cout << harrypopote.putData();

    Tape elchavo = Tape();
    elchavo.getData();
    std::cout << elchavo.putData();

    Sales venta = Sales();
    venta.getData();
    std::cout << venta.putData();
    return 0;
}
