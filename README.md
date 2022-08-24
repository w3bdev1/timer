# timer
A minimal commandline timer in C

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
