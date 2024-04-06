# md
This command line utility  extracts code blocks from Markdown files.

## Build
To build the `md` binary, run `make`. This will create a binary named `md` in the current directory. The `md` binary reads a stream of Markdown from stdin and prints the block at user specified index to stdout.

## Usage
Pipe the Markdown formatted text to the `md` binary.

```bash
cat how_to_use_nmap_example.md | ./md [block_index] > run_nmap.sh
```

