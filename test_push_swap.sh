#!/bin/bash

# Colour for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Function for testing and counting operations
test_numbers() {
    result=$(./push_swap $@ | wc -l)
    sorted=$(./push_swap $@ | ./checker_OS $@)
    printf "${YELLOW}Test [$@]: ${NC}"
    if [ "$sorted" == "OK" ]; then
        printf "${GREEN}OK${NC} ($result moves)\n"
    else
        printf "${RED}KO${NC}\n"
    fi
}

# Basic cases
echo "=== Casos básicos ==="
test_numbers 2 1
test_numbers 1 2 3
test_numbers 2 1 3
test_numbers 3 2 1
test_numbers 3 1 2

# Cases with 5 numbers
echo -e "\n=== Casos con 5 números ==="
test_numbers 1 5 2 4 3
test_numbers 5 4 3 2 1
test_numbers 2 3 4 5 1

# Cases with negative numbers
echo -e "\n=== Casos con negativos ==="
test_numbers -1 5 -2 4 -3
test_numbers -5 -4 -3 -2 -1
test_numbers 2 -3 4 -5 1

# Borderline cases
echo -e "\n=== Casos límite ==="
test_numbers 2147483647 -2147483648 0
test_numbers 42 2147483647 -2147483648

# Error Cases
echo -e "\n=== Casos de error ==="
echo -n "Número duplicado: "
./push_swap 1 2 2 3

echo -n "Número fuera de rango: "
./push_swap 1 2 2147483648 3

echo -n "Argumento no numérico: "
./push_swap 1 2 "abc" 3

# Performance test
echo -e "\n=== Tests de rendimiento ==="
echo "100 números aleatorios:"
ARG100=$(seq 1 100 | sort -R | tr '\n' ' ')
test_numbers $ARG100

echo -e "\n500 números aleatorios:"
ARG500=$(seq 1 500 | sort -R | tr '\n' ' ')
test_numbers $ARG500
