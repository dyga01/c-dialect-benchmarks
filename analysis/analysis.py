"""File for analyzing performance data from benchmarks."""

import subprocess
import os
import matplotlib.pyplot as plt

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

    results = {}
    for name, executable in benchmarks.items():
        print(f"Running {name} benchmark...")
        output = run_benchmark(executable)
        print(output)
        if "executed in " in output:
            results[name] = True
        else:
            results[name] = False

    # Plot the results using matplotlib
    labels = list(results.keys())
    compiled = [1 for _ in labels]  # All bars have the same height
    colors = ['green' if results[label] else 'red' for label in labels]
    markers = ['✔' if results[label] else '✘' for label in labels]

    plt.bar(labels, compiled, color=colors)
    for i, marker in enumerate(markers):
        plt.text(i, 1, marker, ha='center', va='bottom', fontsize=12, fontweight='bold')

    plt.xlabel('Benchmarks')
    plt.ylabel('Compilation Status')
    plt.title('Benchmark Compilation Status')
    plt.ylim(0, 1.5)  # Adjust y-axis to make space for markers
    plt.savefig('/usr/src/app/benchmark_results.png')  # Save the plot as an image

if __name__ == "__main__":
    main()