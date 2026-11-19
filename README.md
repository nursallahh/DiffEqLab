# DiffEqLab

[[https://github.com/nursallahh/DiffEqLab/actions/workflows/ci.yml/badge.svg]](https://github.com/nursallahh/DiffEqLab/actions/workflows/ci.yml)

C++20 matematik çekirdeği (`mathcore`) ile Unity arayüzünü birleştiren diferansiyel denklem, sayısal analiz ve oyun fiziği laboratuvarı.

## Derleme ve Test (Build & Test)

```bash
cmake -B build
cmake --build build
ctest --test-dir build -C Debug --output-on-failure