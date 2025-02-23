# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the working directory
WORKDIR /usr/src/app

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    clang \
    curl

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Create a directory for the compiled executables
RUN mkdir -p /usr/src/app/bin

# Compile C programs and place the executables in the bin directory
RUN gcc -o /usr/src/app/bin/buffer-overflow c/buffer-overflow.c || true
RUN gcc -o /usr/src/app/bin/null-pointer-dereference c/null-pointer-dereference.c || true
RUN gcc -o /usr/src/app/bin/use-after-free c/use-after-free.c || true

# Default command to run all C benchmarks
CMD ["sh", "-c", "test -f /usr/src/app/bin/buffer-overflow && /usr/src/app/bin/buffer-overflow; test -f /usr/src/app/bin/null-pointer-dereference && /usr/src/app/bin/null-pointer-dereference; test -f /usr/src/app/bin/use-after-free && /usr/src/app/bin/use-after-free"]