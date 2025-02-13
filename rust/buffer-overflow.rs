use std::time::Instant;

const SIZE: usize = 10;

fn buffer_overflow() {
    let mut buffer = [0u8; SIZE];
    let start = Instant::now();
    for i in 0..=SIZE {  // Out-of-bounds access!
        buffer[i] = b'A';
    }
    let duration = start.elapsed();
    println!("Buffer Overflow executed in {:?} seconds", duration);
}

fn main() {
    buffer_overflow();
}