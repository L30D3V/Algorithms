#include <iostream>

int main() {
    int n1, n2, n3;
    int menor, centro, maior;

    std::cin >> n1 >> n2 >> n3;
    
    if (n1 < n2) {
        if (n1 < n3) {
            menor = n1;
            if (n2 < n3) {
                maior = n3;
                centro = n2;
            } else {
                centro = n3;
                maior = n2;
            }
        } else {
            menor = n3;
            centro = n1;
            maior = n2;
        }
    } else {
        if (n2 < n3) {
            menor = n2;
            if (n1 < n3) {
                maior = n3;
                centro = n1;
            } else {
                centro = n3;
                maior = n1;
            }
        } else {
            menor = n3;
            centro = n2;
            maior = n1;
        }
    }

    std::cout << menor << std::endl;
    std::cout << centro << std::endl;
    std::cout << maior << std::endl;

    std::cout << std::endl;

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    std::cout << n3 << std::endl;

    return 0;
}