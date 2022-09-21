# Bitcoin-miner Example

The current repository contains a solution that provides a way to get a better basic knowledge of how Bitcoin miner works.
Considering that the quantity of zeros at the start of the binary hash sets the difficulty of the challenge, a struct is created and SHA256 is used.

## Dependencies

You should have installed OpenSSL libraries for compiling the project. In Ubuntu you could install by running:

```bash
sudo apt install libssl-dev
```

## How to compile

Just ensure that you link to SSL and Crypto during the compilation time. Also, the include files for OpenSSL must be visible.

```bash
gcc -o main main.c -lssl -lcrypto
```
