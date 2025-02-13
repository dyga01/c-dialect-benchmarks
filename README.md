# C Dialect Benchmarks

An analysis of how different C dialects compare to Rust in terms of performance and memory safety.

### Benchmarks

My goal is to determine what memory safety features these C dialects are missing that Rust has. Here is the plan to run consistent benchmarks to achieve this:

what aspects of memory safety does rust have that checked c does not have. how can i show this through memory safety benchmarks

3 most comon memory vulnerabilities
- buffer overflows
- use-after-free vulnerabilities
- null pointer dereferences

dockerfile for each part and then docker compose for the whole thing












### Resources

- Checked C: [GitHub Repository](https://github.com/checkedc) and [Hello World Sample](https://github.com/checkedc/checkedc/blob/main/samples/hello-world)
- Cyclone: [Cyclone Language](https://cyclone.thelanguage.org/)
- Rust: [Rust Language](https://www.rust-lang.org/)

### Files

- Docker container setup
- Folder containing Checked C, Cyclone, Rust
- Benchmark programs for time measurement and memory safety tests
- Analysis Python files to process and print results
- `.gitignore` for ignoring unnecessary files
- `requirements.txt` for Python dependencies