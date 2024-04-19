#include "colors.h"
#include <vector>
using namespace std;

const Color orange = {255, 165, 0, 255};
const Color darkGrey = {26, 31, 40, 255};   // empty cell color
const Color cyan = {0, 255, 255, 255};
const Color yellow = {255, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color blue = {13, 65, 216, 255};
const Color pink = {255, 192, 203, 255};
const Color lightGreen = {0, 130, 0, 255};

vector<Color> GetCellColors(){
    return {darkGrey,orange,cyan,yellow,red,blue,pink,lightGreen};
}