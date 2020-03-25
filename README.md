# DPKS Getopt

Program based on GNU Getopt [example](https://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html).

## Tools

You need to install G++ and Make on your machine. Clone this repo and compile program using `make`.

## Example

```sh
$ ./cmd_parce_app -v -V20 --version --help -h --list=1,2,3
Version 1.0.0

value = '20'
help function

list of values '1,2,3'
```
