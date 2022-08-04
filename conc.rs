fn make_vec() -> Vec<i32>
{
        let mut vec =  Vec::new();
        vec.push(0);
        vec.push(1);
        vec
}

fn print_vec(vec: Vec<i32>)
{
        for i in vec.iter()
        {
                println!("{}",i);
        }
}

fn use_vec()
{
        let vec = make_vec();
        print_vec(vec);
}

fn main()
{
        use_vec();
}
~
