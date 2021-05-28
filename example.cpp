#include "include/command.hpp"

int main() {
    process::New("echo")
        .Arg("Hello world!")
        .Arg("Hi!")
        .Status()
        .Expect("Hmm. There's an error occured");
}