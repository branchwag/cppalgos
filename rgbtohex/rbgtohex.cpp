#include <string>
#include <map>
//The secret to the whole thing is remembering that hexadecimal means 16.
std::string rgb_to_hex(int r, int g, int b)
{
// with RGB values of 80, 6, 143,
// 80/16 = 5 + 0/16,
// 6/16 = 0 + 6/16, and
// 143/16 = 8 + 15/16;

//with RBG values of r, g, b:
//      r/16 = first + second/16
//      g/16 = third + fourth/16
//      b/16 = fifth + sixth/16

int arr[6] = {};

//  first is r/16 whole number
arr[0] = r/16;
//  second is r%16 
arr[1] = r % 16;
//  third is g/16 whole number
arr[2] = g/16;
//  fourth is g % 16
arr[3] = g % 16;
//  fifth is b/16 whole number
arr[4] = b/16;
//  sixth is b % 16
arr[5] = b % 16;

//10-15 become A-F
std::map<int, char> numberToLetterMap;

    numberToLetterMap[10] = 'A';
    numberToLetterMap[11] = 'B';
    numberToLetterMap[12] = 'C';
    numberToLetterMap[13] = 'D';
    numberToLetterMap[14] = 'E';
    numberToLetterMap[15] = 'F';

for (int i = 0; i < 6; ++i){
    if (arr[i] >= 10) {
        arr[i] = numberToLetterMap[arr[i]];
    }
}

//would need to figure out way of mixing chars and strings here

//then concat the arr and return it 

    return "";
}