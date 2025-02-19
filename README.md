# C Dialect Benchmarks

An analysis of how C and Checked C compare to Rust in terms of memory safety.

## Getting Started

1. **Install the Checked C toolchain**:
   Download the Checked C toolchain tarball from [Checked C Clang Releases](https://github.com/checkedc/checkedc-clang/releases/tag/CheckedC-Clang-12.0.2) and place it in the `checked-c` directory.

2. **Build and run the Docker containers**:
   ```sh
   docker-compose up --build
   ```

## Benchmarks

The benchmarks focus on three common memory vulnerabilities:

- Buffer overflows
- Use-after-free vulnerabilities
- Null pointer dereferences

Each benchmark is implemented in C, Checked C, and Rust to compare how each language handles these vulnerabilities.

## Results

The results of the benchmarks will be analyzed and presented in the `analysis/analysis.py` script. You can run this script to generate a detailed report of the findings.

## Conclusion

This project aims to highlight the differences in memory safety between C, Checked C, and Rust, providing insights into the strengths and weaknesses of each language in handling common memory vulnerabilities.
