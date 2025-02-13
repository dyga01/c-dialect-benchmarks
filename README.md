# C Dialect Benchmarks

An analysis of how different C dialects compare to Rust in terms of performance and memory safety.

### Benchmarks

My goal is to determine what memory safety features these C dialects are missing that Rust has. Here is the plan to run consistent benchmarks to achieve this:

what aspects of memory safety does rust have that checked c does not have. how can i show this through memory safety benchmarks







3 most comon memory vulnerabilities
- buffer overflows
- use-after-free vulnerabilities
- null pointer dereferences

- no dockerfile for rust because it will not compile for now?
- if something doesnt compile then dont make it crash
- integrate checked c too
- use matplotlib to report if the code compiled and the time it took in analysis
- make it just have memory benchmarks and not time. im not concerned about time.


`docker-compose up`
`docker-compose build c-benchmarks`
`docker-compose build analysis`
`docker-compose build`
`docker cp analysis:/usr/src/app/benchmark_results.png ./benchmark_results.png`
