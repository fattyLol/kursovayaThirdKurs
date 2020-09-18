#include "Vigner.h"

std::string Vigner::Execute(std::string text, int params[])
{
    try
    {
        if (params == nullptr)
        {
            throw (std::string)"Не указан параметр сдвига";
        }
        int isDecode;
        int k = 0;
        params[1] ? isDecode = 1 : isDecode = -1;
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] = ('a' + (text[i] + this->key[k++] * isDecode + 26) % 26);
            }
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = ('A' + (text[i] + this->key[k++] * isDecode + 26) % 26);
            }
            if (k == key.size())
            {
                k = 0;
            }
        }
        return text;
    }
    catch (std::string err)
    {
        std::cout << "[Error] " << err << std::endl;
    }
}
