use std::fs::read_to_string;

fn main() {
    let mut first_vec: Vec<i32> = Vec::new();
    let mut second_vec: Vec<i32> = Vec::new();

    for line in read_to_string("../input").unwrap().lines() {
        if let Some((number1, number2)) = line.split_once(' ') {
            first_vec.push(number1.trim().parse::<i32>().unwrap());
            second_vec.push(number2.trim().parse::<i32>().unwrap());
        } else {
            println!("Can't split line to the number!");
        }
    }

    first_vec.sort();
    second_vec.sort();

    let mut result = 0;
    for i in 0..first_vec.len() {
        result += (first_vec[i] - second_vec[i]).abs();
    }

    println!("Distance: {result}");
}
