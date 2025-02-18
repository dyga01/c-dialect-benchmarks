# Use Ubuntu 22.04 as base image
FROM --platform=linux/amd64 ubuntu:22.04

# Install essential packages
RUN apt-get update && apt-get install -y \
    wget \
    tar \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /opt/checkedc

# Copy the Checked C tar file into the container
COPY checked-c/CheckedC-Clang-12.0.0-gnu-ubuntu-22.04.tar.gz .

# Extract and install Checked C
RUN gunzip CheckedC-Clang-12.0.0-gnu-ubuntu-22.04.tar.gz \
    && tar xf CheckedC-Clang-12.0.0-gnu-ubuntu-22.04.tar \
    && rm CheckedC-Clang-12.0.0-gnu-ubuntu-22.04.tar

# Copy the source files into the container
COPY checked-c/buffer-overflow.c /usr/src/app/checked-c/
COPY checked-c/null-pointer-dereference.c /usr/src/app/checked-c/
COPY checked-c/use-after-free.c /usr/src/app/checked-c/

# Add Checked C binaries to PATH
ENV PATH="/opt/checkedc/CheckedC-Clang-12.0.0git-Linux/bin:${PATH}"

# Add Checked C include path
ENV C_INCLUDE_PATH="/opt/checkedc/CheckedC-Clang-12.0.0git-Linux/include:${C_INCLUDE_PATH}"

# Compile Checked C programs and place the executables in the bin directory
RUN clang -o /usr/src/app/bin/checked-c-buffer-overflow /usr/src/app/checked-c/buffer-overflow.c || true
RUN clang -o /usr/src/app/bin/checked-c-null-pointer-dereference /usr/src/app/checked-c/null-pointer-dereference.c || true
RUN clang -o /usr/src/app/bin/checked-c-use-after-free /usr/src/app/checked-c/use-after-free.c || true

# Verify installation
RUN clang --version

# Set default command to bash
CMD ["/bin/bash"]