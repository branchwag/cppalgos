#include <iostream>
#include <string>
#include <vector>

int snow1[] = {1,2,3,4,5,6};
int snow2[] = {4,5,6,1,2,3};

int identical_right(int snow1[], int snow2[], int start) {
    int offset;
    for (offset = 0; offset < 6; offset++){
        if (snow1[offset] != snow2[(start + offset) % 6])
        return 0;
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int offset, snow2_index;
    for (offset = 0; offset < 6; offset++) {
        snow2_index = (start - offset + 6) % 6; // Adjust index for negative offset
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]){
    int start;
    for (start = 0; start < 6; start ++){
        if (identical_right(snow1, snow2, start))
        return 1;
        if (identical_left(snow1, snow2, start))
        return 1;
    }
    return 0;
}

int main () {
    if (are_identical(snow1, snow2)) 
        std::cout << "The arrays are identical." << std::endl;
    else
        std::cout << "The arrays are not identical." << std::endl;
    return 0;

}