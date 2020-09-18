#include "Enigma.h"


char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rotors[3][27] =
{
  "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
  "AJDKSIRUXBLHWTMCQGZNPYFVOE",
  "BDFHJLCPRTXVZNYEIWGAKMUSQO"
};
char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";


long mod26(long a)
{
    return (a % 26 + 26) % 26;
}

int li(char l)
{
    return l - 'A';
}

int indexof(char* array, int find)
{
    return strchr(array, find) - array;
}



std::string Enigma::Execute(std::string text, int params[])
{
    int L = li(key[0]);
    int M = li(key[1]);
    int R = li(key[2]);

    for (int x = 0; x < text.size(); x++) {
        text[x] = toupper(text[x]);
        if (text[x] < 'A' || text[x] > 'Z')
        {
            continue;
        }
        int ct_letter = li(text[x]);

        R = mod26(R + 1);

        char a = rotors[2][mod26(R + ct_letter)];
        char b = rotors[1][mod26(M + li(a) - R)];
        char c = rotors[0][mod26(L + li(b) - M)];

        char ref = reflector[mod26(li(c) - L)];

        int d = mod26(indexof(rotors[0], alpha[mod26(li(ref) + L)]) - L);
        int e = mod26(indexof(rotors[1], alpha[mod26(d + M)]) - M);
        char f = alpha[mod26(indexof(rotors[2], alpha[mod26(e + R)]) - R)];

        text[x] = f;
    }

    return text;
}
