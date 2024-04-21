#include "colors.h"
#include <vector>
using namespace std;

const Color orange = {255, 140, 0, 255};
const Color Gray = {26, 31, 40, 255};   // empty cell color
const Color green = {0, 255, 200, 255};
const Color yellow = {255, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color blue = {13, 65, 216, 255};
const Color pink = {255, 105, 180, 255};
const Color lightGreen = {0, 200, 0, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color lightPurple = {200, 150, 245, 255};
const Color darkPurple = {40, 0, 95, 255};

vector<Color> GetCellColors(){
    return {Gray,orange,green,yellow,red,blue,pink,lightGreen};
}