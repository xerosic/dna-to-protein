#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define CODON_LEN 3

std::map<std::string, std::string> genetic_code {
    {"UUU", "FEN"}, {"UUC", "FEN"}, {"UUA", "LEU"}, {"UUG", "LEU"},
    {"UCU", "SER"}, {"UCC", "SER"}, {"UCA", "SER"}, {"UCG", "SER"},
    {"UAU", "TIR"}, {"UAC", "TIR"}, {"UAA", "STOP"}, {"UAG", "STOP"},
    {"UGU", "CIS"}, {"UGC", "CIS"}, {"UGA", "STOP"}, {"UGG", "TRI"},

    {"CUU", "LEU"}, {"CUC", "LEU"}, {"CUA", "LEU"}, {"CUG", "LEU"},
    {"CCU", "PRO"}, {"CCC", "PRO"}, {"CCA", "PRO"}, {"CCG", "PRO"},
    {"CAU", "IST"}, {"CAC", "IST"}, {"CAA", "GLU"}, {"CAG", "GLU"},
    {"CGU", "LEU"}, {"CGC", "LEU"}, {"CGA", "LEU"}, {"CGG", "LEU"},

    {"AUU", "ISO"}, {"AUC", "ISO"}, {"AUA", "ISO"}, {"AUG", "START"},
    {"ACU", "TRE"}, {"ACC", "TRE"}, {"ACA", "TRE"}, {"ACG", "TRE"},
    {"AAU", "ASP"}, {"AAC", "ASP"}, {"AAA", "LIS"}, {"AAG", "LIS"},
    {"AGU", "SER"}, {"AGC", "SER"}, {"AGA", "SER"}, {"AGG", "SER"},

    {"GUU", "VAL"}, {"GUC", "VAL"}, {"GUA", "VAL"}, {"GUG", "VAL"},
    {"GCU", "ALA"}, {"GCC", "ALA"}, {"GCA", "ALA"}, {"GCG", "ALA"},
    {"GAU", "ASP"}, {"GAC", "ASP"}, {"GAA", "GLU"}, {"GAG", "GLU"},
    {"GGU", "GLI"}, {"GGC", "GLI"}, {"GGA", "GLI"}, {"GGG", "GLI"}, };


/// <summary>
/// Splits an exon into individual codons
/// </summary>
/// <param name="exon"></param>
/// <returns>A vector of all the codons</returns>
std::vector<std::string> split_exon(std::string exon)
{
    int numsstrings = exon.length() / CODON_LEN;
    std::vector<std::string> ret;

    for (auto i = 0; i < numsstrings; i++)
    {
        ret.push_back(exon.substr(i * CODON_LEN, CODON_LEN));
    }

    // If there are leftover characters, the sequence is wrong.
    if (exon.length() % CODON_LEN != 0)
    {
        throw std::runtime_error("Wrong exon sequence.");
    }

    return ret;
}

/// <summary>
/// Translates a DNA codon into a mRNA codon.
/// </summary>
/// <param name="codon"></param>
/// <returns>Translated mRNA codon</returns>
std::string translate_codon(std::string codon) {
    std::string translatedCodon = "XXX";

    for (int i = 0; i < codon.length(); i++) {
        switch (codon[i]) {
            case 'G':
                translatedCodon[i] = 'C';
                break;
            case 'A':
                translatedCodon[i] = 'U';
                break;
            case 'C':
                translatedCodon[i] = 'G';
                break;
            case 'T':
                translatedCodon[i] = 'A';
                break;
        }
    }

    return translatedCodon;
}

/// <summary>
/// Returns the right protein from the specified codon.
/// </summary>
/// <param name="codon"></param>
/// <returns>Protein's first three letters</returns>
std::string translate_to_protein(std::string codon) {
    return genetic_code[codon];
}
