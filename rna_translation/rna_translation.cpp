#include "main.h"

int main()
{
    std::string exon;
    std::vector<std::string> codon;

    std::cout << "Super omega roby divisore di esoni 2000" << std::endl << "Inserisci l'esone maturo come la prozia di Reus: ";
    std::cin >> exon;

    codon = split_exon(exon);

    std::cout << "\nDNA -> mRNA\n" << std::endl;

    for (auto& i : codon)
    {
        std::cout << translate_codon(i) << " ";
    }

    std::cout << std::endl << "\nmRNA -> Proteine\n" << std::endl;

    for (auto& i : codon)
    {
        std::cout << translate_to_protein(translate_codon(i)) << " ";
    }
    
    std::cout << std::endl;
}