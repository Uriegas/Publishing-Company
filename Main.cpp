#include "Publication.hpp"

int main(void){
    Publication mipublicacion = Publication();
    mipublicacion.getData();
    std::cout << mipublicacion.putData();

    Book harrypopote = Book();
    harrypopote.getData();
    std::cout << harrypopote.putData();
    return 0;
}
