# Peek

Peek is a command-line tool for searching words in files efficiently.

## Features
- Searches for a given word in files.
- Supports multi-threading for faster searches.
- Outputs results to the terminal.
- Uses a temporary file for large result sets.

## Installation

Clone the repository and build the project:

```sh
git clone https://github.com/murshidkc/peek.git
cd peek
make
```

## Usage

Run the tool with:

```sh
./peek <directory_path> <search_word>
```

Example:

```sh
./peek ./test out
If want to search hidden files add -a flag
./peek ./test out -a
If want to search long string including spaces and special characters wrap it with ""
./peek test/ "how could"
```

## Building

To compile manually:

```sh
gcc -Wall -Wextra -O2 -Iheaders -o peek src/main.c -lm
```

## Contributing

Feel free to open issues or submit pull requests to improve the project.

## License

This project is licensed under the MIT License.

