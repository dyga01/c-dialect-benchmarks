fn use_after_free() {
    let ptr = Box::new(42);  // Allocating memory
    let raw_ptr = Box::into_raw(ptr);  // Convert Box to raw pointer

    // Free the memory without using unsafe
    // This will not compile because converting raw pointer back to Box is unsafe
    Box::from_raw(raw_ptr);

    // Accessing freed memory without using unsafe
    // This will not compile because dereferencing a raw pointer is unsafe
    let value = *raw_ptr;

    println!("Use-After-Free executed");
}

fn main() {
    use_after_free();
}