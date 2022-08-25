# timer
A minimal commandline timer in C

## Screencast
![A screen cast showing timer](./timer.gif)

## Build

        make

## Synopsis
    
        timer [-m minutes] [-s seconds] [-t minutes:seconds] [-hv]

## Options

       -m minutes
              number of minutes to count.

       -s seconds
              number of seconds to count.

       -t minutes:seconds
              timestring having higher priority than -m and -s.

       -h     show help information

       -v     show version number

## Examples

### 2 minutes timer

       timer -m 2

### 30 seconds timer

       timer -s 30

### 2 minutes 30 seconds timer

       timer -t 2:30

### Issues to consider
- [x] Use standard header for boolean
- [x] Use block for `if`
- [ ] Initialize every variable with value
- [ ] Use `unisigned int` for min and sec
- [ ] `timer -t :` segfaults
- [ ] Either `-s -m` or `-t` flags
- [ ] Make `clean` target `.PHONY`
- [ ] Streamline multiple exits
- [ ] Try to be platform independent (`unistd.h`)
- [ ] Try to use safe versions of string functions
- [ ] Write comparisons in the way that left side is constant.
- [ ] const correctness on each function parameter and, if applicable, on variables
