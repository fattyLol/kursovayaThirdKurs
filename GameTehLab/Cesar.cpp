#include "Cesar.h"

std::string Cesar::Execute(std::string text, int params[])
{
    try
    {
        if (params == nullptr)
        {
            throw (std::string)"Не указан параметр сдвига";
        }
        int shift = params[0];
        int isDecode;
        params[1] ? isDecode = 26 - 2 * params[0] : isDecode = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] = ('a' + (text[i] - 'a' + shift + isDecode) % 26);
            }
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = ('A' + (text[i] - 'A' + shift + isDecode) % 26);
            }
        }
        return text;
    }
    catch (std::string err)
    {
        std::cout << "[Error] " << err << std::endl;
    }
}
