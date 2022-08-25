#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_help() {
  printf("Usage: timer [-t minutes:seconds] | [-m minutes] [-s seconds]\n");
}

void print_version() { printf("Version 0.1\n"); }

void print_error(char *s) { fprintf(stderr, "Error: %s", s); }

void start_timer(int min, int sec) {
  if (sec > 59) {
    print_error("Number out of bounds\n");
    exit(4);
  }
  while (min >= 0 && sec >= 0) {
    printf("Timer: %02d:%02d", min, sec);
    fflush(stdout);
    if (sec == 0) {
      min--;
      sec = 59;
    } else {
      sec--;
    }
    sleep(1);
    printf("\r"); // Go to start
  }
  printf("Timer: Time up!\n");
}

int count_chars(char *s, char ch) {
  int count = 0;
  while (*s != '\0') {
    if (*s == ch)
      count++;
    s++;
  }
  return count;
}

void parse_time(char *time, int *min, int *sec) {
  *min = atoi(strtok(time, ":"));
  *sec = atoi(strtok(NULL, ":"));
}

int main(int argc, char *argv[]) {
  int min = 0;
  int sec = 0;
  char *time;
  bool tflag = false;
  bool mflag = false;
  bool sflag = false;
  int option;

  while ((option = getopt(argc, argv, "hvt:m:s:")) != -1) {
    switch (option) {
    case 'h': {
      print_help();
      return 0;
    }
    case 'v': {
      print_version();
      return 0;
    }
    case 't': {
      tflag = true;
      time = optarg;
      break;
    }
    case 'm': {
      mflag = true;
      min = atoi(optarg);
      break;
    }
    case 's': {
      sflag = true;
      sec = atoi(optarg);
      break;
    }
    default: {
      print_error("For help: timer -h\n");
      return 1;
    }
    }
  }

  if (!tflag && !mflag && !sflag) {
    print_error("No valid options found. For help: timer -h\n");
    return 2;
  }

  if (tflag) {
    if (count_chars(time, ':') != 1) {
      print_error(
          "timestring need to in minutes:seconds format. For help: timer -h\n");
      return 3;
    } else {
      parse_time(time, &min, &sec);
    }
  }
  start_timer(min, sec);
  return 0;
}
