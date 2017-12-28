#define DTOI(d) (((d.year) * 10000) + ((d.month) * 100) + (d.day))

struct date { int month, day, year; };

int compare_dates(struct date d1, struct date d2);
int compare_dates_alt(struct date d1, struct date d2);
int day_of_year(struct date d);

int day_of_year(struct date d) {
    int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        day = 0,
        century_leap_year = (d.year % 100 == 0 && d.year % 400 == 0),
        regular_leap_year = (d.year % 100 != 0 && d.year % 4 == 0);

    if (century_leap_year || regular_leap_year) {
        days_per_month[1]++;
    }

    for (int i = 1; i < d.month; i++) {
        day += days_per_month[i-1];
    }

    day += d.day;
    return day;
}

int compare_dates(struct date d1, struct date d2) {
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    } else if (d1.month < d2.month) {
        return -1;
    } else if (d1.month > d2.month) {
        return 1;
    } else if (d1.day < d2.day) {
        return -1;
    } else if (d1.day > d2.day) {
        return 1;
    } else {
        return 0;
    }
}

/* cast the date to an integer of yyyymmdd and compare that */
int compare_dates_alt(struct date d1, struct date d2) {
    if (DTOI(d1) < DTOI(d2)) {
        return -1;
    } else if (DTOI(d1) > DTOI(d2)) {
        return 1;
    } else {
        return 0;
    }
}
