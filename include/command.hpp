// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef COMMAND_COMMAND_HPP
#define COMMAND_COMMAND_HPP

#include <iostream>
#include <string>
#include <vector>

class ExitStatus {
public:
    bool error     = false;
public:
    ExitStatus() = default;
    ~ExitStatus()= default;

    void Expect(std::string error) noexcept(false) {
        if(this->error) { std::cerr << error << '\n'; }
    }
};

class Command {
    std::string command,
                args   ;

    void    Add (std::string arg) noexcept { this->args.append(" " + arg); }
    Command Make()                noexcept {
        Command x; x.command = this->command; x.args = this->args; return x;
    }
public:
    void New(std::string command) noexcept {
        this->command = command;
    }

    Command Arg(std::string arg) noexcept {
        this->Add(arg); return this->Make();
    }

    Command Args(std::vector<std::string> args) noexcept {
        for(std::string& arg : args) {
            this->Add(arg);
        } return this->Make();
    }

    ExitStatus Status() noexcept {
        ExitStatus x;
        x.error = std::system((this->command + " " + this->args).c_str()); return x;
    }
};

namespace process {
    Command New(std::string command) {
        Command x; x.New(command); return x;
    }
}

#endif // COMMAND_COMMAND_HPP
