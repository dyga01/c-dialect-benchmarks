# Use the official Ubuntu image as the base image
FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    cmake \
    ninja-build \
    clang \
    lld \
    python3 \
    python3-pip \
    python3-setuptools \
    curl \
    wget \
    unzip \
    build-essential

# Clone Checked C repositories
WORKDIR /opt
RUN git clone https://github.com/microsoft/checkedc-clang.git checkedc-clang
RUN git clone https://github.com/microsoft/checkedc.git checkedc

# Build Checked C Compiler
WORKDIR /opt/checkedc-clang
RUN mkdir build && cd build && \
    cmake -G Ninja \
      -DCMAKE_BUILD_TYPE=Release \
      -DLLVM_ENABLE_PROJECTS="clang" \
      -DLLVM_TARGETS_TO_BUILD="X86" \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      ../llvm && \
    ninja clang clangd lld && ninja install

# Set environment variables
ENV PATH="/usr/local/bin:$PATH"

# Copy benchmark source files to container
WORKDIR /usr/src/app
COPY . /usr/src/app

# Build benchmark executables
WORKDIR /usr/src/app/checked-c
RUN gcc -o /usr/src/app/bin/checked-c-buffer-overflow buffer-overflow.c -fcheckedc-extension && \
    gcc -o /usr/src/app/bin/checked-c-null-pointer-dereference null-pointer-dereference.c -fcheckedc-extension && \
    gcc -o /usr/src/app/bin/checked-c-use-after-free use-after-free.c -fcheckedc-extension

# Set up an entrypoint to allow running shell commands
ENTRYPOINT ["/bin/bash"]