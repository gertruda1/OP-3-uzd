#include "antrastes_vektorius.h"
#include "antrastes_list.h"
#include "antrastes_deque.h"
#include "antrastes2.h"

int main ()
{
    char konteineris; std::cout <<std::endl;
    std::cout << "vector (v) / list (l) / deque (d)? --> "; std::cin >> konteineris;
    koks_konteineris (konteineris, 'v', 'l', 'd');
    if (konteineris == 'v') vektorius();
    else if (konteineris == 'l') listas();
    else if (konteineris == 'd') deque();
    return 0;
}