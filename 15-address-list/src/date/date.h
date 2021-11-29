#ifndef date_h
#define date_h

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

Date *string_to_date(const char s[11]);

char *date_to_string(Date *);

#endif // date_h
