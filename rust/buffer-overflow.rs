const SIZE: usize = 10;

fn buffer_overflow() {
    let mut buffer = [0u8; SIZE];

    for i in 0..=SIZE {  // This will cause a compilation error!
        buffer[i] = b'A';
    }

    println!("Buffer Overflow executed");
}

fn main() {
    buffer_overflow();
}