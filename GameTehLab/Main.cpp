#include "Command.h"
#include "Cesar.h"
#include "Invoker.h"

/**
 * Клиентский код может параметризовать отправителя любыми командами.
 */

int main() {
    setlocale(LC_ALL, "Rus");
    Invoker* invoker = new Invoker;
    invoker->OpenApp();
    invoker->IsReady();
    delete invoker;
    return 0;
}