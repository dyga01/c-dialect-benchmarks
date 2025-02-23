# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /usr/src/app

# Install dependencies and Rust
RUN apt-get update && apt-get install -y curl build-essential \
    && curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y \
    && . $HOME/.cargo/env

# Copy the source files into the container
COPY . .

# Create a directory for the compiled executables
RUN mkdir -p /usr/src/app/bin

# Compile Rust programs and place the executables in the bin directory
RUN /root/.cargo/bin/rustc -o /usr/src/app/bin/rust-buffer-overflow rust/buffer-overflow.rs || true
RUN /root/.cargo/bin/rustc -o /usr/src/app/bin/rust-null-pointer-dereference rust/null-pointer-dereference.rs || true
RUN /root/.cargo/bin/rustc -o /usr/src/app/bin/rust-use-after-free rust/use-after-free.rs || true

# Default command to run all Rust benchmarks
CMD ["sh", "-c", "test -f /usr/src/app/bin/rust-buffer-overflow && /usr/src/app/bin/rust-buffer-overflow; test -f /usr/src/app/bin/rust-null-pointer-dereference && /usr/src/app/bin/rust-null-pointer-dereference; test -f /usr/src/app/bin/rust-use-after-free && /usr/src/app/bin/rust-use-after-free"]