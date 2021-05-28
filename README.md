# Command
## Command, ::process::Command like syscalls in C++.

```cpp
process::New("echo")
        .Arg("Hello world!")
        .Arg("Hi!")
        .Status()
        .Expect("Hmm. There's an error occurred");
```

### Command licensed under the terms of MIT License.
