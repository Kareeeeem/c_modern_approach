# Basic types notes

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

Type of a *decimal* integer is normally `int`. If value is too lange
than it'll be `long int`, if it's still to large the compiler'll try
`unsigned long int`. For *octal* or *hexadecimal* it'll try `int` ->
`unsigned int` -> `long int` -> `unsigned long int`.

C99 rule for *decimal* integers is the smallest of `int` -> `long int`
-> `long long int`. For *octal* or *hexadecimal* it's `int`-> `unsigned
int`-> `long int`-> `unsigned long int`-> `long long int`-> `unsigned
long long int`.

Can append U/u or L/l to contants to force a constant to be `unsigned` and/or
`long` respectively.

C99 constants can end with LL/ll to indicate `long long int`

## Integer overflow

Overflow on signed integers in undefined behavior.

Overflow on `unsigned` integers we get the result `% 2^n`, where `n` is the
width of the integer.
