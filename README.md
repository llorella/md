# Code Block Parser\n\n
## Description
The Code Block Parser program takes an input of code blocks from `stdin` and filters out code blocks of a particular type specified as a command-line argument. It then presents the user with a selection of matching code blocks to choose from, eventually printing the chosen code block to `stdout`.
## Features
- Parses and filters code blocks based on their type (e.g., `python`, `c++`, `shell`, etc.)\n- Allows the user to select from matching code blocks.
- - Provides an option to add an extension for unrecognized code block types.
## Dependencies
- A C++ compiler supporting C++11 or higher
- - Standard C++ Library
- - Make (for building the project)
## Compilation
A working `Makefile` is provided with this project for ease of compilation.To compile the program, navigate to the directory containing the `Makefile` and source code, and then run:```bash\nmake\n```\n\nThis will produce an executable named `code_block_parser` (or another name as specified in the `Makefile`).
## Usage
Run the program with the desired code block type as an argument:\n```bash\n./code_block_parser <type>\n```\nFor example:\n```bash\n./code_block_parser python\n```\nAfter running the program, paste the code blocks into the terminal, or pipe the input from another program or file.\n\n
### Example:\n\nTo filter Python code blocks from a Markdown file:\n\n```bash\ncat example.md | ./code_block_parser python\n```\n\n
## License\n\nThis project is open source and available under the [MIT License](LICENSE).\n

