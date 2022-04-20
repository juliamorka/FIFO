#include <iostream>
#include "FQueue.h"
int main()
{
    FQueue testQueue;
    FQINFO* t[5];
    for (int i = 0; i < 5; i++)
    {
        t[i] = new FQINFO(i);
        testQueue.FQEnqueue(t[i]);
    }
    cout << "Queue: " << endl;
    testQueue.FQPrintQueue();
    FQINFO* pdel;
    cout << "\nIs queue empty? " << testQueue.FQEmpty() << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "wejscie do petli nr. " << i+1 << endl;
        pdel = testQueue.FQDequeue();
        int a = pdel->nKey;
        cout << "usunieto " << i << " element, wartosc = " << a << endl;
    }
    cout << "Is queue empty now? " << testQueue.FQEmpty() << endl; 
    return 0;
}