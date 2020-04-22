#include "AuxiliaryMethods.h"

string AuxiliaryMethods::explodeStringLine (int position, string _textLine) {
    string singleObject = "";
    int countPosition = 1;
    int stringSize = _textLine.size();
    for (int i = 0; i < stringSize; i++) {
        if (_textLine[i] == '|') {
            if (countPosition == position) {
                return singleObject;
            } else {
                countPosition++;
                singleObject = "";
            }
        } else
            singleObject += _textLine[i];
    }
    return singleObject;    // to pozniej zmienic
}
