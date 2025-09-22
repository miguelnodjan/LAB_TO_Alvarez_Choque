#include <iostream>
#include <vector>
using namespace std;

int countChange(int money, vector<int> coins) {
    if (money == 0) {
        return 1;
    }
    if (money < 0 || coins.empty()) {
        return 0;
    }
    return countChange(money - coins[0], coins) + countChange(money, vector<int>(coins.begin() + 1, coins.end()));
}

int main(int argc, char const *argv[])
{
    vector<int> denominaciones;
    int cambio;
    int nueDen;
    
    cout << "Ingresa la cantidad de cambio a dar: ";
    cin >> cambio;
    
    cout << "Ingresar las denominaciones de moneda (0 cuando termine): ";
    while (true)
    {
        cin >> nueDen;
        if (nueDen == 0) {
            break;
        }
        denominaciones.push_back(nueDen);
    }
    
    int resultado = countChange(cambio, denominaciones);
    cout << "El número de formas diferentes de dar cambio es: " << resultado << endl;
    
    return 0;
}