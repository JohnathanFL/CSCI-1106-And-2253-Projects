use std::io;



fn main() {
    println!("{}", unsignedToBinary(12));
}

fn unsignedToBinary(mut num: u32) -> String {
    let mut remainder: u32 = 0;
    let mut finalNum = String::new();

    while num != 0 {
        remainder = num % 2;
        num /= 2;

        finalNum = format!("{}{}", remainder, finalNum)
    }

    while(finalNum.len() != 32) {
        finalNum = format!("{}{}", "0", finalNum);
    }
    // return
    finalNum
}

fn arrayToString(ar: [u32; 32]) -> String {
    let mut result = String::new();

    for i in 0..32 {
        result += ar[i];
    }

    // return
    result
}

fn displayBinary(input: String) {
    println(input);
}

fn displayOctal(input: String) {
    let mut parts: [String; 11];
    let mut finalNum = String::new();

    parts[0] = input.get(0..1);
    parts[0] = format!("{}{}", "0", parts[0]);

    for(i = 2 cnt = 1; i + 3 < 35; i += 3, cnt++) {

    }
}

fn displayHex(input: String) {

}

fn displayDec(input: String) {

}

fn addBinary(strNum1: String, strNum2: String, result: [u32; 32]) {

}

fn runTests(num: u32, addNum1: u32, addNum2: u32) {

}