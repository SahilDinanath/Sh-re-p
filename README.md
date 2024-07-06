# Custom Grep Tool
[Screencast from 2024-07-06 13-38-40.webm](https://github.com/SahilDinanath/Sh-re-p/assets/46680594/f029d790-5b9a-4772-93ba-e24335a2b0e7)

This repository contains a custom implementation of the `grep` command-line tool, utilizing a custom regex engine. The regex engine can be found at [RegexEngine](https://github.com/SahilDinanath/RegexEngine).
- Includes example text files for testing and demonstration purposes.
## Features

- Supports NFA evaluated regular expressions as listed in the [RegexEngine](https://github.com/SahilDinanath/RegexEngine) repository.
- Provides a `grep`-like interface for searching text files with regular expressions.
  
## Building the Project

To build the project, simply run:

```sh
make
```

## Running Examples

You can run examples by executing the `main` program with a regex pattern and a text file as arguments. For example:

```sh
./main "Dracula" ./examples/dracula.txt
```

In this example:
- The first argument `"Dracula"` is the regex expression.
- The second argument `./examples/dracula.txt` is the path to the text file.

## Examples Directory

The `examples` directory contains text files that can be used for testing and demonstration. These files include public domain texts such as:

- `dracula.txt` (Dracula by Bram Stoker)
- `pride_and_prejudice.txt` (Pride and Prejudice by Jane Austen)
- `moby_dick.txt` (Moby Dick by Herman Melville)

## Regular Expressions

The custom regex engine supports the full set of fundamental regular expressions as detailed in the [RegexEngine](https://github.com/SahilDinanath/RegexEngine) repository. Refer to the documentation there for more information on supported expressions and usage.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## Acknowledgments

To Ken Thompson for creating Grep.

