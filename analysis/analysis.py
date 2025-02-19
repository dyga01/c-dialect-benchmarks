"""Analysis File for Printing Benchmark Results."""

import subprocess
import os
from tabulate import tabulate

def run_benchmark(executable):
    """
    Runs the specified benchmark executable and captures its output.

    Args:
        executable (str): The path to the benchmark executable.

    Returns:
        tuple: A tuple containing the output of the benchmark and a boolean indicating if the executable was found and run successfully.
    """
    if os.path.isfile(executable):
        result = subprocess.run([executable], capture_output=True, text=True)
        output = result.stdout
        return output, True
    else:
        return f"{executable} not found.", False

def main():
    """
    Main function to run all benchmarks and display the results in a table format.
    """
    benchmarks = {
        "C Buffer Overflow": "/usr/src/app/bin/buffer-overflow",
        "C Null Pointer Dereference": "/usr/src/app/bin/null-pointer-dereference",
        "C Use-After-Free": "/usr/src/app/bin/use-after-free",
        "Rust Buffer Overflow": "/usr/src/app/bin/rust-buffer-overflow",
        "Rust Null Pointer Dereference": "/usr/src/app/bin/rust-null-pointer-dereference",
        "Rust Use-After-Free": "/usr/src/app/bin/rust-use-after-free",
        "Checked C Buffer Overflow": "/usr/src/app/bin/checked-c-buffer-overflow",
        "Checked C Null Pointer Dereference": "/usr/src/app/bin/checked-c-null-pointer-dereference",
        "Checked C Use-After-Free": "/usr/src/app/bin/checked-c-use-after-free",
    }

    results = {}
    for name, executable in benchmarks.items():
        print(f"Running {name} benchmark...")
        output, compiled = run_benchmark(executable)
        print(output)
        results[name] = compiled

    # Create a table to display the results
    table_data = [["Benchmark", "Compiled"]]
    for name, compiled in results.items():
        table_data.append([name, "✔" if compiled else "✘"])

    # Print the table to the terminal
    print(tabulate(table_data, headers="firstrow", tablefmt="grid"))

if __name__ == "__main__":
    main()