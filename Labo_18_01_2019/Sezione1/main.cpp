#include <iostream>
#include <vector>
#include <algorithm>
#include "MyArray.h"

using namespace std;

// Implementazioni funzioni per il tipo MyArray
void copyMyArray(const MyArray &source, MyArray &dest) {
    for (int i=0;i<dest.length;++i)
        dest.array[i]=source.array[i];
}
void readMyArray(MyArray &dest) {
    for (int i=0;i<dest.length;++i) {
        cout<<"inserisci l'elemento di indice "<<i<<": ";
        cin>>dest.array[i];
        cout << endl;
    }
}
void printMyArray(const MyArray &source) {
    cout<<'['<<source.array[0];
    for (int i = 1; i < source.length; ++i) {
        cout<<", "<<source.array[i];
    }
    cout<<']';
}
void sortMyArray(MyArray &a) {
    sort(begin(a.array), end(a.array));
}
// Implementazioni funzioni per il tipo Occurrence*
void printOccurenceList(const Occurrence *const list) {
    const Occurrence* tmp=list;
    if(nullptr==list) {
        cout << "lista vuota";
        return;
    }
    while (nullptr!=tmp){
        cout<<"---><n: "<<tmp->number<<", o: "<<tmp->occurrences<<"> ";
        tmp=tmp->next;
    }
}


// Funzioni per la gestione dei menu e dei test

void showMenu(string msg, const vector<string>& menu){
    cout<<endl<<msg<<endl;
    for (int i = 1; i <= menu.size(); ++i) {
        cout<<i<<'\t'<<menu.at(i-1)<<endl;
    }
}
// Gets a choice in [1,maxChoice]
int getChoice(int maxChoice){
    int choice=0;
    cin>>choice;
    while(choice<=0||choice>maxChoice){
        cout<<endl<<"scelta non riconosciuta, riprovare: ";
        cin.clear();
        cin.ignore();
        cin>>choice;
    }
    return choice;
}
// Makes the call under test and prints its result
void printTestResult(bool testOddOccurrencesCount, const MyArray& arg){
    if(testOddOccurrencesCount)
        cout << oddOccurrencesCount(arg) << endl;
    else
        printOccurenceList(occurrenceList(arg));
}

int main() {
    char continuing='y';
    vector<string> testArgChoices;
    testArgChoices.push_back("array [4, 7, 2, 4, 1, 7, 7, 7,-3,0]");
    testArgChoices.push_back("array inserito dall'utente");
    do {
        showMenu("scegli l'array su cui vuoi eseguire il test",testArgChoices);
        int choice=getChoice(testArgChoices.size());
        MyArray arg;
        switch (choice){
            case 1 : {
                MyArray tmp={4, 7, 2, 4, 1, 7, 7, 7,-3,0};
                copyMyArray(tmp, arg);
                break;
            }
            case 2:
                readMyArray(arg);
        }
        vector<string> testFunChoices;
        testFunChoices.push_back("oddOccurrencesCount");
        testFunChoices.push_back("occurrenceList");
        showMenu("scegli la funzione su cui vuoi eseguire il test",testFunChoices);
        int funChoice=getChoice(testFunChoices.size());
        cout<<endl<<"sull'array"<<endl;
        printMyArray(arg);
        cout<<endl<<"il risultato di "<<((1==funChoice)?"oddOccurrencesCount e': ":"occurrenceList e': ")<<endl;
        printTestResult(1==funChoice,arg);
        cout<<endl<<"vuoi continuare con altri test? ('y'/'n' default 'n')"<<endl;
        cin>>continuing;
        continuing = tolower(continuing);
    } while('n'!=continuing);
    return 0;
}