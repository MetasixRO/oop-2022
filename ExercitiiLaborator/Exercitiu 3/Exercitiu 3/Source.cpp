#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

void solutie(char s[256], char mat[50][50],int &n) {
    char aux[50];
    //char mat[50][50];
    int i = -1, j, h;
    char* p;
    scanf("%[^\n]s", s);  // s are sirul de caract
    p = strtok(s, " ,."); // p preia cate un cuvant
    while (p != NULL) {
        i++;
        strcpy(mat[i], p); // pun cuvantul in matricea de cuvinte
        p = strtok(NULL, " ,.");
    }
    n = i;
    for (j = 0; j < i; j++)
        for (h = j + 1; h <= i; h++)
            if (strlen(mat[j]) < strlen(mat[h])) {
                strcpy(aux, mat[j]);
                strcpy(mat[j], mat[h]);
                strcpy(mat[h], aux);
            }
    /* s[0] = NULL;
    for (j = 0; j <= i; j++) {
        strcat(s, mat[j]);
        strcat(s, " ");
    }
    */
}

int main() {
    int n = 0;
    char s[256];
    char matrice[50][50];
    solutie(s,matrice,n);
    for (int i = 0; i <= n; i++) {
        printf("%s \n", matrice[i]);
    }

    return 0;
}
