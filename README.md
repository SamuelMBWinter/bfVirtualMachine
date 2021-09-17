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

## Usage


