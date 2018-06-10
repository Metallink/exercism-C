#include "isogram.h"

bool is_isogram(const char phrase[]) {

        int count = 0;
        int len = strlen(phrase);

        for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {

                        if (phrase[i] == phrase[j])
                                count += 1;

                        if (count > 1)
                                return false;
                        else
                                count = 0;
                }
        }
        return true;
}
