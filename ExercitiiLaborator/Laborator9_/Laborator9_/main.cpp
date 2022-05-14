#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template <class T, class Y>
struct pereche {
    T key;
    Y value;
};

template <class T, class Y>
class Iterator {
    struct tuple {
        T key;
        Y value;
        int index;
    };
    pereche<T, Y>* ptr;
    int index;

  public:
    Iterator(pereche<T, Y>* ptr, int index) : ptr(ptr), index(index) {
    }

    bool operator!=(Iterator const& other) {
        return ptr != other.ptr;
    }

    Iterator& operator++() {
        ptr++;
        index++;
        return *this;
    }

    tuple operator*() {
        tuple treime;
        treime.key   = ptr->key;
        treime.value = ptr->value;
        treime.index = index;
        return treime;
    }
};

template <class T, class Y>
class Map {
    pereche<T, Y> vector[30];
    int size;

  public:
    Map() {
        size = 0;
    }

    Y& operator[](T key) {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key)
                return vector[i].value;
        vector[size].value = {};
        vector[size].key   = key;
        size++;
        return vector[size - 1].value;
    }

    Iterator<T, Y> begin() {
        return { vector, 0 };
    }

    Iterator<T, Y> end() {
        return { vector + size, size };
    }

    int Count() {
        return size;
    }

    bool Get(const T& key, Y& value) {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key) {
                value = vector[i].value;
                return true;
            }
        return false;
    }

    void Clear() {
        for (int i = 0; i < size; i++) {
            vector[i].key   = NULL;
            vector[i].value = NULL;
            for (int j = i; j < size; j++)
                vector[j] = vector[j + 1];
        }
        size = 0;
    }

    bool Delete(const T& key) {
        for (int i = 0; i < size; i++) {
            if (vector[i].key == key) {
                vector[i].key   = NULL;
                vector[i].value = NULL;
                for (int j = i; j < size; j++)
                    vector[j] = vector[j + 1];
            }
        }
        size--;
        return false;
    }

    void Set(T key, Y value) {
        for (int i = 0; i < size; i++) {
            if (vector[i].key == key) {
                vector[i].value = value;
            }
        }
    }

    bool Includes(const Map<T, Y>& mapare) {
        int ok = 1;
        for (int i = 0; i < mapare.size; i++) {
            ok = 0;
            for (int j = 0; j < size && ok == 0; j++) {
                if (vector[j].key == mapare.vector[i].key)
                    ok = 1;
            }
            if (ok == 0)
                return false;
        }
        return true;
    }
};

int main()

{
    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    printf("\n");
    m.Delete(20);

    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    printf("\n");
    Map<int, const char*> maping;
    maping[10] = "C++";
    maping[30] = "test";
    // maping[15] = "POO";

    if (m.Includes(maping) == false)
        printf("Maparea maping nu este inclusa in maparea m \n");
    else
        printf("Maparea maping este inclusa in maparea m \n");

    printf("\n\nMaparea numita \"maping\"\n");
    for (auto [key, value, index] : maping)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    int numar;
    numar = m.Count();
    printf("\nNumarul de elemente din maparea m este : %d \n", numar);

    m.Set(30, "Testing.c");
    printf("\n\n\nMaparea m dupa ce s-a adaugat cuvantul Testing.c pe cheia 30\n");
    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    printf("\n\n");

    m.Clear();

    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    printf("\n\nMaparea m este goala \n");

    return 0;
}