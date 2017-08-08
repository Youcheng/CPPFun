Catch Framework
===============
[C++ Automated Cases in Headers](https://github.com/philsquared/Catch)

What is catch ?
---------------
    Catch stands for C++ Automated Test Cases in Headers and is a multi-paradigm automated test framework for C++ and Objective-C (and, maybe, C).
    It is implemented entirely in a set of header files, but is packaged up as a single header for extra convenience.

- Single header deployment
- No external dependencies
- Tests names are free-form strings
- Powerful "Assertions"
- Excellent error mesages
- Sections


How to use catch?
-----------------
[HeaderFileDownloadLink](https://github.com/philsquared/Catch/releases/download/v1.9.6/catch.hpp)
[CLion Catch Support](https://www.jetbrains.com/help/clion/catch-tests-support.html)


```
    #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
    #include "catch.hpp

    TEST_CASE( "TestName", "[tag1][tag2]" ) {
    ...
    }

TestName


Tags
    To Categorize tests

```


How to to run test binary from command line
-------------------------------------------
- run test_cases per tags
```
    [cmake-build-debug  (master)]$ ./catchExample -l
    All available test cases:
      Factorials are computed 1
          [A]
      Factorials are computed 2
          [A]
      Factorials are computed 3
          [B]
      Factorials are computed 4
          [A][B]
    4 test cases

    [cmake-build-debug  (master)]$ ./catchExample "[A]"
    ===============================================================================
    All tests passed (12 assertions in 3 test cases)

    [cmake-build-debug  (master)]$ ./catchExample "[B]"
    ===============================================================================
    All tests passed (8 assertions in 2 test cases)

    [cmake-build-debug  (master)]$ ./catchExample "~[A]"
    ===============================================================================
    All tests passed (4 assertions in 1 test case)

    [cmake-build-debug  (master)]$ ./catchExample "~[B]"
    ===============================================================================
    All tests passed (8 assertions in 2 test cases)

    [cmake-build-debug  (master)]$ ./catchExample "[A],[B]"
    ===============================================================================
    All tests passed (16 assertions in 4 test cases)

```

- run test_case per test names
```
[cmake-build-debug  (master)]$ ./catchExample "Factorials are computed 2"
===============================================================================
All tests passed (4 assertions in 1 test case)
```


command line help
-----------------
```
[cmake-build-debug  (master)]$ ./catchExample -h

Catch v1.9.6
usage:
  catchExample [<test name, pattern or tags> ...] [options]

where options are:
  -?, -h, --help                display usage information
  -l, --list-tests              list all/matching test cases
  -t, --list-tags               list all/matching tags
  -s, --success                 include successful tests in output
  -b, --break                   break into debugger on failure
  -e, --nothrow                 skip exception tests
  -i, --invisibles              show invisibles (tabs, newlines)
  -o, --out <filename>          output filename
  -r, --reporter <name>         reporter to use (defaults to console)
  -n, --name <name>             suite name
  -a, --abort                   abort at first failure
  -x, --abortx <no. failures>   abort after x failures
  -w, --warn <warning name>     enable warnings
  -d, --durations <yes|no>      show test durations
  -f, --input-file <filename>   load test names to run from a file
  -#, --filenames-as-tags       adds a tag for the filename
  -c, --section <section name>  specify section to run
  --list-test-names-only        list all/matching test cases names only
  --list-extra-info             list all/matching test cases with more info
  --list-reporters              list all reporters
  --order <decl|lex|rand>       test case order (defaults to decl)
  --rng-seed <'time'|number>    set a specific seed for random numbers
  --force-colour                force colourised output (deprecated)
  --use-colour <yes|no>         should output be colourised

For more detail usage please see the project docs
```


Catch Macros
------------
- REQUIRE
    Single macro for all/most assertions needs

    REQUIRE(2+2 == 5);  // Abort test  --> Test Fail

- REQUIRE_FALSE

- CHECK
    CHECK(2+2 == 5); // Continue test --> Test Fail

- CHECK_FALSE

- INFO
    INFO("customer name is: " << customer.get_name() )

- WARN

- FAIL

- CAPTURE


Test Fixtures
-------------
[Manual](https://github.com/philsquared/Catch/blob/master/docs/test-fixtures.md)
![TestFixture](https://github.com/Youcheng/CPPFun/tree/blob/UnitTestFramework/TestFixture.png)

Sections
--------
[Manual](https://github.com/philsquared/Catch/blob/master/docs/test-cases-and-sections.md)