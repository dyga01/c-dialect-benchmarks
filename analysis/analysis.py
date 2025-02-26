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
        return f"{executable} failed to compile.\n", False

def list_files(directory):
    """
    Lists all files in the specified directory.

    Args:
        directory (str): The path to the directory.

    Returns:
        list: A list of file names in the directory.
    """
    try:
        files = os.listdir(directory)
        return files
    except FileNotFoundError:
        return []

def main():
    """
    Main function to run all benchmarks and display the results in a table format.
    """
    bin_directory = "/usr/src/app/bin"
    
    benchmarks = {
        "C Buffer Overflow": "buffer-overflow",
        "C Null Pointer Dereference": "null-pointer-dereference",
        "C Use-After-Free": "use-after-free",
        "Rust Buffer Overflow": "rust-buffer-overflow",
        "Rust Null Pointer Dereference": "rust-null-pointer-dereference",
        "Rust Use-After-Free": "rust-use-after-free",
        "Checked C Buffer Overflow": "checked-c-buffer-overflow",
        "Checked C Null Pointer Dereference": "checked-c-null-pointer-dereference",
        "Checked C Use-After-Free": "checked-c-use-after-free",
    }

    # List and print all files in the bin directory
    files = list_files(bin_directory)
    print(f"Files in {bin_directory}: {files}")

    results = {}
    for name, executable_name in benchmarks.items():
        executable_path = f"{bin_directory}/{executable_name}"
        print(f"Running {name} benchmark...")
        output, compiled = run_benchmark(executable_path)
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