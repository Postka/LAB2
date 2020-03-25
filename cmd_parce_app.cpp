#include <stdio.h>

#include <stdlib.h>

#include <getopt.h>

/* Flag set by ‘--verbose’. */
static int verbose_flag;

void list(char * lst);
void value(char * val);
void version();
void help();

int main(int argc, char ** argv) {
  int c;
  bool l = true;
  bool v = true;
  bool h = true;
  bool V = true;

  while (1) {
    static struct option long_options[] = {
      {
        "list",
        optional_argument,
        0,
        'l'
      },
      {
        "version",
        no_argument,
        0,
        'v'
      },
      {
        "help",
        no_argument,
        0,
        'h'
      },
      {
        "value",
        required_argument,
        0,
        'V'
      },
      {
        0,
        0,
        0,
        0
      }
    };
    /* getopt_long stores the option index here. */
    int option_index = 0;

    c = getopt_long(argc, argv, "l::vhV:",
      long_options, & option_index);

    /* Detect the end of the options. */
    if (c == -1)
      break;

    switch (c) {
    case 0:
      /* If this option set a flag, do nothing else now. */
      if (long_options[option_index].flag != 0)
        break;
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      printf("\n");
      break;

    case 'l':
      if (l) {
        list(optarg);
        l = false;
      }
      break;

    case 'v':
      if (v) {
        version();
        v = false;
      }
      break;

    case 'h':
      if (h) {
        help();
        h = false;
      }
      break;

    case 'V':
      if (V) {
        value(optarg);
        V = false;
      }
      break;

    default:
      abort();
    }
  }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
    exit(1);
  }

  exit(0);
}

void list(char * lst) {
  printf("list of values '%s'\n", lst);
}

void value(char * val) {
  printf("value = '%s'\n", val);
}

void version() {
  puts("Version 1.0.0\n");
}

void help() {
  puts("help function\n");
}
