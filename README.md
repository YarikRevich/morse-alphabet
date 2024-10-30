# morse-alphabet

[![Build](https://github.com/YarikRevich/morse-alphabet/actions/workflows/build.yml/badge.svg)](https://github.com/YarikRevich/morse-alphabet/actions/workflows/build.yml)
[![StandWithUkraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)

## General Information

A design of application for embedded devices, which acts as **ASCII-to-morse-alphabet** converter.

![](./docs/high-level-design.png)

![](./docs/finite-state-machine-design.png)

## Setup

All setup related operations are processed via **Makefile** placed in the root directory.

In order to build the test benches into project local **bin** directory it's required to execute the following command.
```shell
make build
```

## Use cases

All the test benches are located in **./tests** directory and are automatically executed during project build.