# Brainf\*ck Virtual Machine

This program runs brainf\*ck programs stored in UTF-8 encoded plaintext files with the .bf extension. These programs consist of only 8 characters
- `>` : Increment the data pointer (moves 1 space to the right)
- `<` : Decrement the data pointer (moves 1 space to the left)
- `+` : Increment the Byte where the pointer is pointing by one
- `-` : Decrement the Byte where the pointer is pointing by one
- `,` : Take 1 byte of input and store it at the data pointer
- `.` : Output the byte of data at the data pointer
- `[` : if the byte at the data pointer is zero, skip to the command after `]`
- `]` : if the byte at the data pointer is non-zero, jump the corresponding `[`

## Installation

Use a C compiler to compile the `bfvm.c` file into a binary called `bfvm`. If you are using the *gcc* compiler the command is `$ gcc bfvm.c -o bfvm`. `

## Usage

*Hello world* in brainf\*ck is supplied in the repository.

```bash
$ bfvm <FILE>
...
$ bfvm helloworld.bf
Hello World!
```

