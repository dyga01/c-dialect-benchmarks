use std::time::Instant;

fn use_after_free() {
    let ptr = Box::new(42);
    let start = Instant::now();
    drop(ptr);  // Memory freed
    unsafe {
        let value = *ptr;  // UAF! Accessing freed memory.
    }
    let duration = start.elapsed();
    println!("Use-After-Free executed in {:?} seconds", duration);
}

fn main() {
    use_after_free();
}