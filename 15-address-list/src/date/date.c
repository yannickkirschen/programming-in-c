#include <stdio.h>
#include <stdlib.h>

#include "date.h"

Date *string_to_date(const char s[11]) {
    if (s[2] != '.' || s[5] != '.') {
        return NULL;
    }

    char day[3];
    char month[3];
    char year[5];

    day[0] = s[0];
    day[1] = s[1];
    day[2] = 0;

    month[0] = s[3];
    month[1] = s[4];
    month[2] = 0;

    year[0] = s[6];
    year[1] = s[7];
    year[2] = s[8];
    year[3] = s[9];
    year[4] = 0;

    int d = (int) strtol(day, NULL, 10);
    int m = (int) strtol(month, NULL, 10);
    int y = (int) strtol(year, NULL, 10);

    Date *date = malloc(sizeof(Date));
    date->day = d;
    date->month = m;
    date->year = y;

    return date;
}

char *date_to_string(Date *date) {
    char *s = malloc(sizeof(char) * 10);
    sprintf(s, "%i.%i.%i", date->day, date->month, date->year);
    return s;
}
