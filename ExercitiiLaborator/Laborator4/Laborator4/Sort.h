#pragma once

#define _CRT_SECURE_NO_WARNINGS

class Sort

{
    int* elem;
    unsigned count;
    bool ascendent;

  public:
    Sort(unsigned count, int min, int max);//

    Sort(int v[], unsigned count);//

    Sort(unsigned count, ...); //

    Sort(char* sir);//

    Sort(int count) : elem(new int[count]{ 1, 2, 3 }){};

    void InsertSort(bool ascendent = false);//

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);//

    void Print();//

    int GetElementsCount();//

    int GetElementFromIndex(int index);//
};
