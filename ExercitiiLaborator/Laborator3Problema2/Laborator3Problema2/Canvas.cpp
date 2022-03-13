#include "Canvas.h"
#include <string.h>
#include <stdarg.h>
#include <cstdio>
#include <iostream>

Canvas::Canvas(int width, int height) {
    this->width = width; //coloane
    this->height = height; //linii
    Clear();
    
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * ray)
                SetPoint(i, j, ch);

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            if (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * ray)
                SetPoint(i, j, ch);

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) { 
    //top e linia //right col //bottom linia //left coloana
    DrawLine(top, right, bottom, right, ch);
    DrawLine(top, left, top, right, ch);
    DrawLine(bottom, left, bottom, right, ch);
    DrawLine(top, left, bottom, left, ch);
    


}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            SetPoint(i, j, ch);
            SetPoint(i, j, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    poza[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    if (x1 != x2 && y1 != y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x  = x1;
        int y  = y1;
        int p  = 2 * dy - dx;

        while (x < x2) {
            if (p >= 0) {
                SetPoint(x, y, ch);
                y = y + 1;
                p = p - 2 * dx;
            } else {
                SetPoint(x, y, ch);
                p = p + 2 * dy;
            }
            x = x + 1;
        }
    }  else {
        if (y1 == y2) {
            int x = x1;
            while (x != x2) {
                SetPoint(x, y1, ch);
                x++;
            }
        } else if (x1 == x2) {
            int y = y1;
            while (y != y2) {
                SetPoint(x1, y, ch);
                y++;
            }
        }

    }
    
    
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", poza[i][j]);
        printf("\n");
    }
}

void Canvas::Clear() {
    memset(poza, ' ', sizeof(poza));
}
