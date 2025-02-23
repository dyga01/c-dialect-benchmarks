fn null_pointer_dereference() {
    let ptr: *const i32 = std::ptr::null();  // Declare a null pointer

    // Intentional null pointer dereference without using unsafe
    // This will not compile because dereferencing a null pointer is unsafe
    let value = *ptr;  // Dereferencing NULL will result in a compile-time error

    println!("Null Pointer Dereference executed");
}

fn main() {
    null_pointer_dereference();
}