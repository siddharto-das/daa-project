# daa-project

## Using this repository

To compile the binary `employees`:

    make

The binary will be compiled into a directory named `bin/`.

To prepare the documentation:

    make doc

## Using the programme

The programme `employees` takes as input a rooted tree and produces as
output the same tree with each node labelled with coupons such that
the labelling satisfies _Question 1_:

> In organization ABC, the employees have an underlying hierarchy,
> where the CEO is at the top and every other employee has exactly one
> manager. An employee can be the manager to one or more
> employees. Any employee is familiar with the work of her manager and
> the works of her immediate sub-ordinates.
>
> It was decided to give away gift coupons for all employees
> (including the CEO) as New Year presents. By mistake, the gift
> coupons ordered were of three different denominations: 1000, 2000
> and 3000. It was decided that every employee will receive a gift
> coupon of denomination different from her manager. However, if an
> employee receives a gift coupon of larger denomination than her
> manager, she is sure to be given a negative rating by her manager in
> a fit of jealousy. Design an algorithm to decide how to distribute
> gift coupons among employees so that the number of employees who get
> a negative rating is minimized.

A tree is specified by a sequence of non-negative integers separated
by whitespace listing the number of children of each node in the tree
(including the leaf nodes) in pre-order.

The output is a human-readable description of a tree resembling the output of the Linux utility `tree`.

Given below is an example of a typical use case.

    $ employees
    3 4 0 0 2 1 0 0 0 3 3 0 2 0 0 0 0 0 1 1 5 0 0 0 0 0
    3000
    ├── 2000
    │   ├── 1000
    │   ├── 1000
    │   ├── 3000
    │   │   ├── 2000
    │   │   │   └── 1000
    │   │   └── 1000
    │   └── 1000
    ├── 2000
    │   ├── 3000
    │   │   ├── 1000
    │   │   ├── 2000
    │   │   │   ├── 1000
    │   │   │   └── 1000
    │   │   └── 1000
    │   ├── 1000
    │   └── 1000
    └── 1000
        └── 3000
            └── 2000
                ├── 1000
                ├── 1000
                ├── 1000
                ├── 1000
                └── 1000
