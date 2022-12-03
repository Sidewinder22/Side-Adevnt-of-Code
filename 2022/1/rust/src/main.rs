use std::fs::File;
use std::io::{BufReader, BufRead, Error};

fn main() -> Result<(), Error> {

    let file_name = "../input";

    let input = File::open(file_name)?;
    let buffered = BufReader::new(input);

    let mut biggest_sum : u32 = 0;
    let mut sum : u32 = 0;

    for line in buffered.lines() {
        let line = line?.clone();
        
        if line.trim().is_empty() {
            if sum > biggest_sum {
                biggest_sum = sum;
            }
            sum = 0;
        }
        else {
            sum += line.parse::<u32>().unwrap();
        }
    }

    println!("Result: {}", biggest_sum);
    
    Ok(())
}
