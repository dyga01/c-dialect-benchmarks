# Use the official Rust image as a parent image
FROM rust:latest

# Set the working directory
WORKDIR /usr/src/app

# Copy the Rust source files into the container
COPY rust/*.rs ./

# Create a directory for the compiled executables
RUN mkdir -p /usr/src/app/bin

# Compile Rust programs and place the executables in the bin directory
RUN rustc buffer-overflow.rs -o /usr/src/app/bin/rust-buffer-overflow || true
RUN rustc null-pointer-dereference.rs -o /usr/src/app/bin/rust-null-pointer-dereference || true
RUN rustc use-after-free.rs -o /usr/src/app/bin/rust-use-after-free || true

# Default command to run all Rust benchmarks
CMD ["sh", "-c", "test -f /usr/src/app/bin/rust-buffer-overflow && /usr/src/app/bin/rust-buffer-overflow; test -f /usr/src/app/bin/rust-null-pointer-dereference && /usr/src/app/bin/rust-null-pointer-dereference; test -f /usr/src/app/bin/rust-use-after-free && /usr/src/app/bin/rust-use-after-free"]