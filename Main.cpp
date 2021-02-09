#include "Publication.hpp"

int main(void){
    Publication mipublicacion = Publication();
    mipublicacion.getData();
    std::cout << mipublicacion.putData() << '\n';

    return 0;
}
