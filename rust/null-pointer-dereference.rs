use std::time::Instant;

fn null_pointer_dereference() {
    let ptr: *const i32 = std::ptr::null();
    let start = Instant::now();
    unsafe {
        let value = *ptr;  // Crash! Dereferencing NULL.
    }
    let duration = start.elapsed();
    println!("Null Pointer Dereference executed in {:?} seconds", duration);
}

fn main() {
    null_pointer_dereference();
}