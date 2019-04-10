//
// Created by Mau on 13/01/2019.
//

#ifndef MYARRAY_H
#define MYARRAY_H

struct MyArray{
    static const int length=10;
    int array[length];
};
struct Occurrence{
    int number;
    int occurrences;
    Occurrence* next;
};
// Funzioni che dovete implementare
int oddOccurrencesCount(const MyArray& a);
Occurrence* occurrenceList(const MyArray& a);


// Funzioni definite da noi. Se vi servono potete usarle
void copyMyArray(const MyArray& source, MyArray& dest);
void readMyArray(MyArray& dest);
void printMyArray(const MyArray& source);
void sortMyArray(MyArray& a);
void printOccurenceList(const Occurrence* const list);
#endif //MYARRAY_H
