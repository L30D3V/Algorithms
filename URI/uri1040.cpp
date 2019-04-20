#include <iostream>
#include <iomanip>

int main() {
    double n1, n2, n3, n4;
    double average, extra;

    while(std::cin >> n1 >> n2 >> n3 >> n4) {
        average = (n1*2 + n2*3 + n3*4 + n4)/10.0;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Media: " << average << std::endl;

        if (average < 5.0)
            std::cout << "Aluno reprovado." << std::endl;
        else if (average >= 7)
            std::cout << "Aluno aprovado." << std::endl;
        else {
            std::cout << "Aluno em exame." << std::endl;

            std::cin >> extra;
            std::cout << "Nota do exame: " << extra << std::endl;
            average = (average + extra)/2.0;

            if (average >= 5)
                std::cout << "Aluno aprovado." << std::endl;
            else
                std::cout << "Aluno reprovado." << std::endl;

            std::cout << "Media final: " << average << std::endl;
        }
    }
    
    return 0;
}