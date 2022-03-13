#include "Canvas.h"

int main() {
    Canvas canvas(50, 50);
     //x1 top:: y2 left:: x2 top:: y2 right
    canvas.DrawRect(1, 45, 41, 50, 'R');
    canvas.FillRect(1, 45, 41, 50, 'R');
    canvas.DrawCircle(35, 25, 7, 'C');

    
    canvas.Print();
}