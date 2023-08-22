#include <iostream>
#include "include/Matriz.h"
using namespace std;

int main(int argc, char* argv[]) {
    Matriz prototipo(10, 10);
    prototipo.mostra_matriz();

    prototipo.set_auto();
    prototipo.mostra_matriz();

    return 0;
}