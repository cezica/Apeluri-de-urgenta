#include "Conexiune.h"
#include "SFML/Graphics.hpp"

using namespace std;

int main()
{
	Conexiune C;
	cout << "Astept clienti..." << endl;
	C.start_comunicare();
}