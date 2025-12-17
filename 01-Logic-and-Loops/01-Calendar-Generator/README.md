# Project 01: The Forever Calendar

## 🎯 Goal

Create a program that generates a **perfectly formatted calendar** for **any year entered by the user (from 1900 onwards)**.

The calendar should correctly handle leap years, calculate the correct day alignment, and print a clean, readable grid using formatted output.

---

## 1. Core Concepts

### 🔢 Modulo Arithmetic (`%`)

* Used to **wrap days of the week** within the range `0–6`.
* Helps determine how days shift from one year or month to the next.

### 🔀 Complex Conditionals

* Required to implement the **4–100–400 rule** for leap years accurately.

### 🔁 Loops & Accumulators

* Used to **accumulate day offsets** starting from a fixed historical point.
* Allows the program to compute the correct weekday for any future year.

### 🖨️ Formatting (`printf`)

* Controls **spacing and alignment** so dates appear in a clean calendar grid.

---

## 2. The Logic Design

### A. Leap Year Algorithm

A year is a **leap year** if:

1. It is divisible by **400** → ✅ Leap year
2. Else if it is divisible by **100** → ❌ Not a leap year
3. Else if it is divisible by **4** → ✅ Leap year
4. Otherwise → ❌ Normal year

#### Examples

| Year | Result          |
| ---- | --------------- |
| 2000 | Leap Year ✅     |
| 1900 | Not Leap Year ❌ |
| 2024 | Leap Year ✅     |
| 2023 | Normal Year ❌   |

---

### B. Anchor Day Algorithm

Computers don’t inherently know weekdays, so we calculate them **relative to a known fixed date**.

#### Anchor Point

* **January 1, 1900 → Monday (Index 0)**

#### Yearly Shift

| Year Type   | Days | `days % 7` | Shift   |
| ----------- | ---- | ---------- | ------- |
| Normal Year | 365  | 1          | +1 day  |
| Leap Year   | 366  | 2          | +2 days |

#### Algorithm Steps

```c
Initialize total_days_offset = 0;

For y = 1900 to (target_year - 1):
    If y is leap year:
        total_days_offset += 2;
    Else:
        total_days_offset += 1;

StartDay = total_days_offset % 7;
```

* `StartDay` represents the weekday index (0–6) for **January 1st** of the target year.

---

## 3. Sample Output

```
Enter a year: 2024

  ------------ January ------------
  Mon  Tue  Wed  Thu  Fri  Sat  Sun
    1    2    3    4    5    6    7
    8    9   10   11   12   13   14
   15   16   17   18   19   20   21
   22   23   24   25   26   27   28
   29   30   31

  ------------ February ------------
  Mon  Tue  Wed  Thu  Fri  Sat  Sun
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29
```

---

## 4. Implementation Plan

### 🧠 `isLeapYear(int year)`

* Returns `1` if the year is a leap year.
* Returns `0` otherwise.

```c
int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}
```

---

### �� `getFirstDayOfYear(int year)`

* Calculates the weekday index (0–6) of **January 1st**.
* Uses 1900 as the anchor year.

```c
int getFirstDayOfYear(int year) {
    int offset = 0;
    for (int y = 1900; y < year; y++) {
        offset += isLeapYear(y) ? 2 : 1;
    }
    return offset % 7;
}
```

---

### 🖨️ `printCalendar(int year, int startDay)`

#### Steps:

1. Create an array of days per month.
2. Update February to 29 if leap year.
3. Loop through all 12 months.
4. Print leading spaces based on `startDay`.
5. Print dates, breaking lines every 7 days.

```c
int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

if (isLeapYear(year))
    daysInMonth[1] = 29;
```

---

## ✅ Outcome

By combining:

* Modulo arithmetic
* Conditional logic
* Loop-based accumulation
* Careful output formatting

You create a **Forever Calendar** that works for **any year from 1900 onward** with perfect accuracy and alignment.

---

🚀 *This project strengthens your understanding of date logic, control flow, and formatted output — a classic and powerful C programming exercise!*
