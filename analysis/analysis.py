import subprocess
import os
import matplotlib.pyplot as plt
import re

def run_benchmark(executable):
    if os.path.isfile(executable):
        result = subprocess.run([executable], capture_output=True, text=True)
        output = result.stdout
        match = re.search(r"executed in ([\d.]+) seconds", output)
        if match:
            time = float(match.group(1))
        else:
            time = None
        return output, time
    else:
        return f"{executable} not found.", None

def main():
    benchmarks = {
        "C Buffer Overflow": "/usr/src/app/bin/buffer-overflow",
        "C Null Pointer Dereference": "/usr/src/app/bin/null-pointer-dereference",
        "C Use-After-Free": "/usr/src/app/bin/use-after-free",
    }

    results = {}
    for name, executable in benchmarks.items():
        print(f"Running {name} benchmark...")
        output, time = run_benchmark(executable)
        print(output)
        if time is not None:
            results[name] = (True, time)
        else:
            results[name] = (False, None)

    # Create a table to display the results
    fig, ax = plt.subplots(figsize=(10, 2 + len(results) * 0.5))  # Adjust the figure size based on the number of benchmarks
    ax.axis('tight')
    ax.axis('off')
    table_data = [["Benchmark", "Compiled", "Execution Time (seconds)"]]
    for name, (compiled, time) in results.items():
        table_data.append([name, "✔" if compiled else "✘", f"{time:.12f}" if time is not None else "N/A"])

    table = ax.table(cellText=table_data, colLabels=None, cellLoc='center', loc='center')
    table.auto_set_font_size(False)
    table.set_fontsize(10)  # Adjust the font size
    table.scale(1.2, 1.2)  # Adjust the scaling

    plt.title('Benchmark Compilation and Execution Time')
    plt.savefig('/usr/src/app/benchmark_results.png')  # Save the table as an image

if __name__ == "__main__":
    main()