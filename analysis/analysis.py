"""File for analyzing performance data from benchmarks."""

import subprocess
import os

def run_benchmark(executable):
    if os.path.isfile(executable):
        result = subprocess.run([executable], capture_output=True, text=True)
        return result.stdout
    else:
        return f"{executable} not found."

def main():
    benchmarks = {
        "C Buffer Overflow": "/usr/src/app/bin/buffer-overflow",
        "C Null Pointer Dereference": "/usr/src/app/bin/null-pointer-dereference",
        "C Use-After-Free": "/usr/src/app/bin/use-after-free",
    }

    for name, executable in benchmarks.items():
        print(f"Running {name} benchmark...")
        output = run_benchmark(executable)
        print(output)

if __name__ == "__main__":
    main()