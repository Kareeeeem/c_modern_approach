# Basic types notes

* [Ints](#integer-types)
* [Floats](#floating-types)

## Integer types

By default `int` types are signed.

16 bit machine

Type | min | max | width |
---- | --- | --- | --- |
`short int` | -32,768 | -32,768 | 16 bits
`unsigned short int` | 0 | 65,535 | 16 bits
`int` | -32,768 | 32,768 | 16 bits
`unsigned int` | 0 | 65,535 | 16 bits
`long int` | -2,147,483,648 | 2,147,483,648 | 32 bits
`unsigned long int` | 0 | 4,294,967,295 | 32 bits

32 bit machine

Type | min | max | width |
---- | --- | --- | --- |
`short int` | -32,768 | -32,768 | 16 bits
`unsigned short int` | 0 | 65,535 | 16 bits
`int` | -2,147,483,648 | 2,147,483,648 | 32 bits
`unsigned int` | 0 | 4,294,967,295 | 32 bits
`long int` | -2,147,483,648 | 2,147,483,648 | 32 bits
`unsigned long int` | 0 | 4,294,967,295 | 32 bits

64 bit machine

Type | min | max | width |
---- | --- | --- | --- |
`short int` | -32,768 | -32,768 | 16 bits
`unsigned short int` | 0 | 65,535 | 16 bits
`int` | -2,147,483,648 | 2,147,483,648 | 32 bits
`unsigned int` | 0 | 4,294,967,295 | 32 bits
`long int` | -9,223,372,036,854,775,807 | 9,223,372,036,854,775,807 | 64 bits
`unsigned long int` | 0 | 18,446,744,073,709,551,615 | 64 bits

C99 introduces `long long int` and `unsigned long long int`. Both are
required to be at least 64 bits wide. C99 allows implementation defined
**extended integer types**.

### Integer constants

Type of a *decimal* integer is normally `int`.

If value is too lange in **C89** it'll try
* `long int` -> `unsigned long int`.  (*decimal* constants)
* `int` -> `unsigned int` -> `long int` -> `unsigned long int`. (*octal* or *hexadecimal* constants)

If value is too lange in **C99** it'll try
* `long int` -> `long int` -> `long long int`. (*decimal* constants)
* `int` -> `unsigned int` -> `long int` -> `unsigned long int` -> `long long int` -> `unsigned long long int`. (*octal* or *hexadecimal* constants)

Append `U`/`u` or `L`/`l` to contants to force `unsigned` and/or `long`.
**C99** constants can end with `LL`/`ll` to indicate `long long int`

### Integer overflow

Overflow on signed integers in undefined behavior.

Overflow on `unsigned` integers we get the result `% 2^n`, where `n` is the
width of the integer.

### Reading/Writing Integers

```c
unsigned int u;

scanf("%u", &u);    /* reads in base 10 */
printf("%u", u);    /* writes in base 10 */
scanf("%o", &o);    /* reads in base 8 */
printf("%o", o);    /* writes in base 8 */
scanf("%x", &x);    /* reads in base 8 */
printf("%x", x);    /* writes in base 8 */

short s;            /* put the letter h before the format character */

scanf("%hd", &s);
printf("%hd", s);

long l;             /* put the letter l before the format character */

scanf("%ld", &s);
printf("%ld", s);

long long ll;       /* C99: put the letters ll before the format character */

scanf("%ld", &s);
printf("%ld", s);
```

## Floating types

Three types:

* `float`       Single-precision floating-point.
* `double`      Double-precision floating-point.
* `long double` Extended-precision floating-point.

The *IEEE Floating-point standard* provides two basic formats for
floating types; single and double precision. Numbers are stored
in a form of scientific notation with each number having three parts:

* sign
* exponent
* fraction

Number of bits reserved for the exponent determines size of the number.
Number of bits in the fraction determines precision.

[Floating point guide](http://floating-point-gui.de/)

| type | smallest pos value | largest value | precision |
| ---- | ------------------ | ------------- | --------- |
| `float` | 1.17459 * 10^-38 | 3.40282 * 10*38 | 6 digits |
| `double` | 2.22507 * 10^-308 | 1.79769 * 10*308 | 15 digits |

The table is only valid for machines that follow the IEEE standard.

`long double` varies from machine to machine. 80 and 128 bits being the
most common sizes.

**C99** categorized floating types into:

* real floating types
    * `float`
    * `double`
    * `long double`
* complex types
    * `float _Complex`
    * `double _Complex`
    * `long double _Complex`

### Floating constants

Be default they are `double`s. Force to be `float` by appending `F`/`f`.

### Reading/writing Floating types

```c
double d;

scanf("%lf", &d);    /* Prepend letter l before format char e, f or g when
                     /* reading. Prepending l when writing is an error in
                     /* C89 and a NOP in C99 */


long double ld;
scanf("%Lf", &ld);   /* prepend letter L before format char when reading. */
print("%Lf", ld);    /* prepend letter L before format char when writing. */
```
